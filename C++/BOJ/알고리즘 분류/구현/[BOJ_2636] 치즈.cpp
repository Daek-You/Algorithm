#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define AIR -1
#define VACUUM 0
#define CHEESE 1
#define AIR_EXPOSED_CHEESE 2

int MaxRow, MaxColumn, NumOfCheeses;
vector<vector<int>> Field;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<Point> AirExposedCheeses;

void Initialize()
{
    cin >> MaxRow >> MaxColumn;
    Field.resize(MaxRow, vector<int>(MaxColumn));

    for (int r = 0; r < MaxRow; r++)
    {
        for (int c = 0; c < MaxColumn; c++)
        {
            cin >> Field[r][c];
            if (Field[r][c] == CHEESE) NumOfCheeses++;
        }
    }
}

void SetExternalAir(int row, int column)
{
    queue<Point> externalAirs;
    Field[row][column] = AIR;
    externalAirs.push(Point(row, column));

    while (!externalAirs.empty())
    {
        row = externalAirs.front().first;
        column = externalAirs.front().second;
        externalAirs.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = row + direction.first;
            int nextColumn = column + direction.second;

            if (nextRow < 0 or nextRow >= MaxRow or nextColumn < 0 or nextColumn >= MaxColumn)
                continue;
            if (Field[nextRow][nextColumn] == CHEESE or Field[nextRow][nextColumn] == AIR)
                continue;
            
            Field[nextRow][nextColumn] = AIR;
            externalAirs.push(Point(nextRow, nextColumn));
        }
    }
}

bool IsAirExposedCheese(int row, int column)
{
    for (const Point& direction : Directions)
    {
        int nextRow = row + direction.first;
        int nextColumn = column + direction.second;

        if (Field[nextRow][nextColumn] == AIR)
            return true;
    }

    return false;
}

void FindAirExposedCheeses()
{
    for (int r = 0; r < MaxRow; r++)
    {
        for (int c = 0; c < MaxColumn; c++)
        {
            if (Field[r][c] == AIR or Field[r][c] == VACUUM or Field[r][c] == AIR_EXPOSED_CHEESE)
                continue;

            if (IsAirExposedCheese(r, c))
            {
                Field[r][c] = AIR_EXPOSED_CHEESE;
                AirExposedCheeses.push(Point(r, c));
            }
        }
    }
}

int RemoveAirExposedCheeses()
{
    int count = AirExposedCheeses.size();

    for (int i = 0; i < count; i++)
    {
        Point position = AirExposedCheeses.front();
        AirExposedCheeses.pop();
        SetExternalAir(position.first, position.second);
    }

    return count;
}

int main()
{
    FAST_IO
    Initialize();
    SetExternalAir(0, 0);

    int numOfCheesesAnHourAgo = NumOfCheeses;
    int currentNumOfCheeses = NumOfCheeses;
    int hour = 0;
    
    while (currentNumOfCheeses > 0)
    {
        FindAirExposedCheeses();
        numOfCheesesAnHourAgo = currentNumOfCheeses;
        currentNumOfCheeses -= RemoveAirExposedCheeses();
        hour++;
    }

    cout << hour << "\n" << numOfCheesesAnHourAgo;
    return 0;
}