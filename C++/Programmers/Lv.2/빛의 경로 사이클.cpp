#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using Direction = pair<int, int>;
#define DIRECTION_COUNT 4

vector<Direction> Directions { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 상 우 하 좌

int GetCycleLength(const vector<string>& grid, vector<vector<vector<bool>>>& visited, int row, int column, int direction)
{
    int maxRow = grid.size(), maxColumn = grid[0].length();
    int pathLength = 0;

    while (!visited[row][column][direction])
    {
        pathLength++;
        visited[row][column][direction] = true;

        switch(grid[row][column])
        {
            case 'L':
                direction = (direction + 3) % DIRECTION_COUNT;
                break;
            case 'R':
                direction = (direction + 1) % DIRECTION_COUNT;
                break;
        }

        // 음수 상황을 고려해야함
        row = (row + Directions[direction].first + maxRow) % maxRow;
        column = (column + Directions[direction].second + maxColumn) % maxColumn;
    }

    return pathLength;
}

vector<int> solution(vector<string> grid)
{
    int maxRow = grid.size(), maxColumn = grid[0].length();
    vector<vector<vector<bool>>> visited(maxRow, vector<vector<bool>>(maxColumn, vector<bool>(DIRECTION_COUNT, false)));
    vector<int> answer;

    for (int row = 0; row < maxRow; row++)
    {
        for (int column = 0; column < maxColumn; column++)
        {
            for (int direction = 0; direction < DIRECTION_COUNT; direction++)
            {
                if (!visited[row][column][direction])
                    answer.push_back(GetCycleLength(grid, visited, row, column, direction));
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}