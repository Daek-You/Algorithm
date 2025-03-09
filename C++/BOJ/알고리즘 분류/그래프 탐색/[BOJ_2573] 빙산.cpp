#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define SEA 0
#define TO_BE_REMOVED -1

int MaxRow, MaxColumn, NumOfIcebergs = 0;
vector<vector<int>> Field;
vector<Point> Directions { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };  // 동, 서, 남, 북
queue<Point> ToBeRemovedIcebergs;

void Initialize()
{
    cin >> MaxRow >> MaxColumn;
    Field.resize(MaxRow, vector<int>(MaxColumn));

    for (int row = 0; row < MaxRow; row++)
    {
        for (int column = 0; column < MaxColumn; column++)
        {
            cin >> Field[row][column];
            if (Field[row][column] != SEA) NumOfIcebergs++;
        }
    }
}

void FindIcebergsToRemove()
{
    // 배열의 첫 번째 행과 열, 마지막 행과 열은 항상 바다로 채워져 있다고 했으므로
    for (int row = 1; row < MaxRow - 1; row++)
    {
        for (int column = 1; column < MaxColumn - 1; column++)
        {
            if (Field[row][column] == SEA or Field[row][column] == TO_BE_REMOVED)
                continue;
            
            int numOfAdjacentSeas = 0;

            for (const Point& direction : Directions)
            {
                int nextRow = row + direction.first;
                int nextColumn = column + direction.second;

                if (Field[nextRow][nextColumn] == SEA)
                    numOfAdjacentSeas++;
            }

            int difference = Field[row][column] - numOfAdjacentSeas;
            Field[row][column] = (difference <= 0) ? TO_BE_REMOVED : difference;

            if (Field[row][column] == TO_BE_REMOVED)
                ToBeRemovedIcebergs.emplace(Point(row, column));
        }
    }
}

void RemoveIcebergs()
{
    int size = ToBeRemovedIcebergs.size();
    for (int i = 0; i < size; i++)
    {
        Point position = ToBeRemovedIcebergs.front();
        ToBeRemovedIcebergs.pop();
        Field[position.first][position.second] = SEA;
        NumOfIcebergs--;
    }
}

void BFS(vector<vector<bool>>& visited, int row, int column)
{
    queue<Point> positions;
    positions.emplace(Point(row, column));
    visited[row][column] = true;

    while (!positions.empty())
    {
        row = positions.front().first;
        column = positions.front().second;
        positions.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = row + direction.first;
            int nextColumn = column + direction.second;

            if (Field[nextRow][nextColumn] == SEA or visited[nextRow][nextColumn])
                continue;
            
            visited[nextRow][nextColumn] = true;
            positions.emplace(Point(nextRow, nextColumn));
        }
    }
}

bool IsSplitIntoTwoChunks()
{
    int numOfIcebergChunks = 0;
    vector<vector<bool>> visited(MaxRow, vector<bool>(MaxColumn, false));

    for (int row = 1; row < MaxRow - 1; row++)
    {
        for (int column = 1; column < MaxColumn - 1; column++)
        {
            if (Field[row][column] == SEA) continue;
            if (visited[row][column]) continue;

            BFS(visited, row, column);
            numOfIcebergChunks++;

            if (numOfIcebergChunks >= 2)
                return true;
        }
    }

    return false;
}

int main()
{
    FAST_IO
    Initialize();

    int year = 0;
    while (true)
    {
        FindIcebergsToRemove();
        RemoveIcebergs();
        year++;

        if (IsSplitIntoTwoChunks()) break;
        else if (NumOfIcebergs <= 0)
        {
            cout << "0";
            return 0;
        }
    }

    cout << year;
    return 0;
}