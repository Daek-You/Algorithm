#include <vector>
#include <queue>

using namespace std;
using Direction = pair<int, int>;
using Position  = pair<int, int>;
#define EMPTY -1
#define OIL   1000000000

vector<Direction> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int MaxRow, MaxColumn;

int BFS(vector<vector<int>>& land, const int oilId, int row, int column)
{
    int maxRow = land.size(), maxColumn = land[0].size();
    int oilArea = 1;

    queue<Position> positions;
    positions.emplace(Position(row, column));
    land[row][column] = oilId;

    while(!positions.empty())
    {
        Position currentPosition = positions.front();
        positions.pop();

        for (const Direction& direction : Directions)
        {
            int nextRow = currentPosition.first + direction.first;
            int nextColumn = currentPosition.second + direction.second;

            if (nextRow < 0 or nextRow >= maxRow or nextColumn < 0 or nextColumn >= maxColumn)
                continue;
            
            if (land[nextRow][nextColumn] != OIL)
                continue;
            
            land[nextRow][nextColumn] = oilId;
            positions.emplace(Position(nextRow, nextColumn));
            oilArea++;
        }
    }

    return oilArea;
}

void ChangeLand(vector<vector<int>>& land)
{
    for (int row = 0; row < MaxRow; row++)
    {
        for (int column = 0; column < MaxColumn; column++)
        {
            if (land[row][column] == 0)         land[row][column] = EMPTY;
            else if (land[row][column] == 1)    land[row][column] = OIL;
        }
    }
}

int solution(vector<vector<int>> land)
{
    // 1. 계산하기 쉽게, 초기 세팅
    MaxRow = land.size();
    MaxColumn = land[0].size();
    ChangeLand(land);

    // 2. BFS를 통해 각 오일 덩어리마다 번호(인덱스)를 매겨, 배열에 덩어리 크기 값을 저장
    vector<int> oilAmounts;
    for (int row = 0; row < MaxRow; row++)
    {
        for (int column = 0; column < MaxColumn; column++)
        {
            if (land[row][column] == EMPTY or land[row][column] < oilAmounts.size())
                continue;
            
            int oilAmount = BFS(land, oilAmounts.size(), row, column);
            oilAmounts.push_back(oilAmount);
        }
    }

    // 3. 한 열씩 시추하여 가장 큰 값 찾기
    int answer = 0;

    for (int column = 0; column < MaxColumn; column++)
    {
        int currentColumnOilAmount = 0;
        vector<bool> visited(oilAmounts.size(), false);

        for (int row = 0; row < MaxRow; row++)
        {
            if (land[row][column] == EMPTY or visited[land[row][column]])
                continue;
            
            visited[land[row][column]] = true;
            currentColumnOilAmount += oilAmounts[land[row][column]];
        }

        answer = max(answer, currentColumnOilAmount);
    }

    return answer;
}