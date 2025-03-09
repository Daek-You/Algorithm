#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using Point = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define EMPTY 0

int N, Q, MaxLength;
vector<int> SkillLevels;
vector<vector<int>> Field;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Initialize()
{
    cin >> N >> Q;
    MaxLength = static_cast<int>(pow(2, N));

    Field.resize(MaxLength, vector<int>(MaxLength));
    SkillLevels.resize(Q);

    for (int row = 0; row < MaxLength; row++)
        for (int column = 0; column < MaxLength; column++)
            cin >> Field[row][column];

    for (int i = 0; i < Q; i++)
        cin >> SkillLevels[i];
}

void Rotate(int startRow, int startColumn, int size)
{
    vector<vector<int>> temp(size, vector<int>(size));

    for (int row = startRow; row < startRow + size; row++)
        for (int column = startColumn; column < startColumn + size; column++)
            temp[column - startColumn][size - (row - startRow) - 1] = Field[row][column];

    for (int row = startRow; row < startRow + size; row++)
        for (int column = startColumn; column < startColumn + size; column++)
            Field[row][column] = temp[row - startRow][column - startColumn];
}

void MeltIce()
{
    vector<vector<int>> newField = Field;

    for (int row = 0; row < MaxLength; row++)
    {
        for (int column = 0; column < MaxLength; column++)
        {
            if (Field[row][column] == EMPTY)
                continue;

            int numOfAdjacentIce = 0;

            for (const Point& direction : Directions)
            {
                int nextRow = row + direction.first;
                int nextColumn = column + direction.second;

                if (nextRow < 0 or nextRow >= MaxLength or nextColumn < 0 or nextColumn >= MaxLength)
                    continue;

                if (Field[nextRow][nextColumn] > EMPTY)
                    numOfAdjacentIce++;
            }

            if (numOfAdjacentIce < 3)
                newField[row][column]--;
        }
    }

    Field = newField;
}


void Divide(const int targetSize, const int currentSize, int leftUpRow, int leftUpColumn)
{
    if (currentSize == targetSize)
    {
        Rotate(leftUpRow, leftUpColumn, currentSize);
        return;
    }

    int mid = currentSize / 2;

    Divide(targetSize, mid, leftUpRow, leftUpColumn);
    Divide(targetSize, mid, leftUpRow, leftUpColumn + mid);
    Divide(targetSize, mid, leftUpRow + mid, leftUpColumn);
    Divide(targetSize, mid, leftUpRow + mid, leftUpColumn + mid);
}

int FindMaximumIceChunkSize(vector<vector<bool>>& visited, int row, int column)
{
    queue<Point> positions;
    int chunkSize = 1;

    positions.push({row, column});
    visited[row][column] = true;

    while (!positions.empty())
    {
        Point current = positions.front();
        positions.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = current.first + direction.first;
            int nextColumn = current.second + direction.second;

            if (nextRow < 0 or nextRow >= MaxLength or nextColumn < 0 or nextColumn >= MaxLength)
                continue;
            
            if (visited[nextRow][nextColumn] or Field[nextRow][nextColumn] == EMPTY)
                continue;
            
            visited[nextRow][nextColumn] = true;
            positions.push({nextRow, nextColumn});
            chunkSize++;
        }
    }

    return chunkSize;
}

int main()
{
    FAST_IO
    Initialize();

    for (const int skillLevel : SkillLevels)
    {
        int gridSize = static_cast<int>(pow(2, skillLevel));
        Divide(gridSize, MaxLength, 0, 0);
        MeltIce();
    }

    vector<vector<bool>> visited(MaxLength, vector<bool>(MaxLength, false));
    int numOfRemainedIce = 0, maxIceChunkSize = 0;

    for (int row = 0; row < MaxLength; row++)
    {
        for (int column = 0; column < MaxLength; column++)
        {
            numOfRemainedIce += Field[row][column];

            if (visited[row][column] or Field[row][column] == EMPTY)
                continue;

            maxIceChunkSize = max(maxIceChunkSize, FindMaximumIceChunkSize(visited, row, column));
        }
    }

    cout << numOfRemainedIce << "\n" << maxIceChunkSize;
    return 0;
}
