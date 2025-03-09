#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using Point = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define START 'S'
#define DESTINATION 'D'
#define WATER '*'
#define EMPTY '.'
#define STONE 'X'
#define VISIT 'O'
#define INVAILD -1

int MaxRow, MaxColumn;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void RiseWater(vector<string>& field, queue<Point>& waterPositions)
{
    int waterCount = waterPositions.size();

    while (waterCount--)
    {
        Point waterPosition = waterPositions.front();
        waterPositions.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = waterPosition.first + direction.first;
            int nextCol = waterPosition.second + direction.second;

            if (nextRow < 0 or nextRow >= MaxRow or nextCol < 0 or nextCol >= MaxColumn)
                continue;
            
            bool isStone = (field[nextRow][nextCol] == STONE);
            bool isDestination = (field[nextRow][nextCol] == DESTINATION);
            bool isWater = (field[nextRow][nextCol] == WATER);

            if (isStone or isDestination or isWater)
                continue;
                
            field[nextRow][nextCol] = WATER;
            waterPositions.emplace(Point(nextRow, nextCol));
        }
    }

}

bool MoveHedgeHog(vector<string>& field, queue<Point>& hedgehogPositions, int& time)
{
    int hedgehogCount = hedgehogPositions.size();

    while (hedgehogCount--)
    {
        Point hedgehogPoisition = hedgehogPositions.front();
        hedgehogPositions.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = hedgehogPoisition.first + direction.first;
            int nextCol = hedgehogPoisition.second + direction.second;

            if (nextRow < 0 or nextRow >= MaxRow or nextCol < 0 or nextCol >= MaxColumn)
                continue;
            
            if (field[nextRow][nextCol] == DESTINATION)
            {
                time++;
                return true;
            }

            bool isStone = (field[nextRow][nextCol] == STONE);
            bool isWater = (field[nextRow][nextCol] == WATER);
            bool isVisit = (field[nextRow][nextCol] == VISIT);

            if (isStone or isWater or isVisit)
                continue;
            
            field[nextRow][nextCol] = VISIT;
            hedgehogPositions.emplace(Point(nextRow, nextCol));
        }
    }

    return false;
}

int FindTimeToCave(vector<string>& field, queue<Point>& waterPositions, queue<Point>& hedgehogPositions)
{
    bool isAlive = false;
    int arrivalTime = 0;

    while (!hedgehogPositions.empty())
    {
        // 1. 물 상승
        RiseWater(field, waterPositions);

        // 2. 고슴도치 이동
        if (isAlive = MoveHedgeHog(field, hedgehogPositions, arrivalTime))
            break;
        arrivalTime++;     
    }

    return isAlive ? arrivalTime : INVAILD;
}

void Initialize(vector<string>& field, queue<Point>& waterPositions, queue<Point>& hedgehogPositions)
{
    for (int row = 0; row < MaxRow; row++)
    {
        cin >> field[row];

        for (int column = 0; column < MaxColumn; column++)
        {
            if (field[row][column] == START)
            {
                hedgehogPositions.emplace(Point(row, column));
                field[row][column] = VISIT;
            }

            else if (field[row][column] == WATER)
                waterPositions.emplace(Point(row, column));
        }
    }
}

int main()
{
    FAST_IO

    // 1. 초기화
    cin >> MaxRow >> MaxColumn;

    vector<string> field(MaxRow);
    queue<Point> waterPositions;
    queue<Point> hedgehogPositions;

    Initialize(field, waterPositions, hedgehogPositions);
    
    // 2. BFS 탐색 시작
    int time = FindTimeToCave(field, waterPositions, hedgehogPositions);

    if (time == INVAILD)
        cout << "KAKTUS";
    else
        cout << time;
    return 0;
}