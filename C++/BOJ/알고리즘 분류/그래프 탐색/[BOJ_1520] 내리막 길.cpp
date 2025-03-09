#include <iostream>
#include <vector>

using namespace std;
using Position = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define UNVISITED -1

vector<Position> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int DFS(const vector<vector<int>>& map, vector<vector<int>>& dp, int row, int col)
{
    if (row == map.size() - 1 and col == map[0].size() - 1)
        return 1;

    if (dp[row][col] != UNVISITED)
        return dp[row][col];

    dp[row][col] = 0;
    for (const Position& direction : Directions)
    {
        int nextRow = row + direction.first;
        int nextCol = col + direction.second;

        if (nextRow < 0 or nextRow >= map.size() or nextCol < 0 or nextCol >= map[0].size())
            continue;
        
        if (map[row][col] <= map[nextRow][nextCol])
            continue;

        dp[row][col] += DFS(map, dp, nextRow, nextCol);
    }

    return dp[row][col];
}


int main()
{
    FAST_IO

    // 1. 입력 받기
    int maxRow, maxCol;
    cin >> maxRow >> maxCol;

    vector<vector<int>> map(maxRow, vector<int>(maxCol));
    for (int row = 0; row < maxRow; row++)
        for (int col = 0; col < maxCol; col++)
            cin >> map[row][col];

    vector<vector<int>> dp(maxRow, vector<int>(maxCol, UNVISITED));
    int answer = DFS(map, dp, 0, 0);

    cout << answer;
    return 0;
}