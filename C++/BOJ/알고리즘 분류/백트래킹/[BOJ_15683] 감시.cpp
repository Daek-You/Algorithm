#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using Point = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define SEE   -1
#define EMPTY 0
#define WALL  6

int MaxRow, MaxColumn, Answer;
vector<vector<int>> Office;
vector<Point> CCTVPositions;
vector<Point> Directions { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 상 우 하 좌

void WatchWithCCTV(stack<Point>& positions, int row, int column, int direction)
{
    direction %= Directions.size();

    while (true)
    {
        row += Directions[direction].first;
        column += Directions[direction].second;

        if (row < 0 or row >= MaxRow or column < 0 or column >= MaxColumn) return;
        if (Office[row][column] == WALL) return;
        if (Office[row][column] != EMPTY) continue;
        
        Office[row][column] = SEE;
        positions.emplace(Point(row, column));
    }
}

void StopWatchingWithCCTV(stack<pair<int, int>>& positions)
{
    while (!positions.empty())
    {
        int row = positions.top().first, column = positions.top().second;
        Office[row][column] = EMPTY;
        positions.pop();
    }
}

int GetBlindSpotCount()
{
    int count = 0;

    for (int row = 0; row < MaxRow; row++)
        for (int column = 0; column < MaxColumn; column++)
            if (Office[row][column] == EMPTY)
                count++;

    return count;
}

void Solution(int cctvIndex)
{
    if (cctvIndex == CCTVPositions.size())
    {
        Answer = min(Answer, GetBlindSpotCount());
        return;
    }

    int row = CCTVPositions[cctvIndex].first;
    int column = CCTVPositions[cctvIndex].second;
    int cctvNumber = Office[row][column];
    stack<pair<int, int>> positions;

    for (int direction = 0; direction < Directions.size(); direction++)
    {
        switch (cctvNumber)
        {
            case 1:
                WatchWithCCTV(positions, row, column, direction);
                break;

            case 2:
                WatchWithCCTV(positions, row, column, direction);
                WatchWithCCTV(positions, row, column, direction + 2);
                break;

            case 3:
                WatchWithCCTV(positions, row, column, direction);
                WatchWithCCTV(positions, row, column, direction + 1);
                break;
                
            case 4:
                WatchWithCCTV(positions, row, column, direction);
                WatchWithCCTV(positions, row, column, direction + 1);
                WatchWithCCTV(positions, row, column, direction + 2);
                break;

            case 5:
                WatchWithCCTV(positions, row, column, direction);
                WatchWithCCTV(positions, row, column, direction + 1);
                WatchWithCCTV(positions, row, column, direction + 2);
                WatchWithCCTV(positions, row, column, direction + 3);
                break;
        }

        Solution(cctvIndex + 1);
        StopWatchingWithCCTV(positions);
    }
}

int main()
{
    FAST_IO
    cin >> MaxRow >> MaxColumn;

    Answer = MaxRow * MaxColumn;
    Office.resize(MaxRow, vector<int>(MaxColumn));

    for (int row = 0; row < MaxRow; row++)
    {
        for (int column = 0; column < MaxColumn; column++)
        {
            cin >> Office[row][column];
            
            if (Office[row][column] != EMPTY and Office[row][column] != WALL)
                CCTVPositions.emplace_back(Point(row, column));
        }
    }

    Solution(0);
    cout << Answer;
    return 0;
}