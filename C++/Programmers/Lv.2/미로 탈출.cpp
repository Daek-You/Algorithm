/* BFS 좀 더 연습해보자. */

#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int rowDirection[4] = { -1, 1, 0, 0 };
int columnDirection[4] = { 0, 0, -1, 1 };

class Info
{
public:
    Info(int row, int column, int currentTime) : _row(row), _column(column), _currentTime(currentTime) { }
    int _row;
    int _column;
    int _currentTime;
};

map<char, pair<int, int>> GetLabelPositions(const vector<string>& maps)
{
    map<char, pair<int, int>> result;

    for (int row = 0; row < maps.size(); row++)
    {
        for (int column = 0; column < maps[row].length(); column++)
        {
            char label = '@';

            if (maps[row][column] == 'S')
                label = 'S';
            else if (maps[row][column] == 'E')
                label = 'E';
            else if (maps[row][column] == 'L')
                label = 'L';

            if (label != '@')
                result.insert(make_pair(label, make_pair(row, column)));
        }
    }

    return result;
}


int CalculateTimeWithBFS(const vector<string>& maps, Info start, Info end, bool& isFindTarget)
{
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    int minTime = 2147483647;
    queue<Info> _queue;

    _queue.push(start);
    visited[start._row][start._column] = true;

    while (!_queue.empty())
    {
        Info current = _queue.front();
        _queue.pop();

        if ((current._row == end._row) and (current._column == end._column))
        {
            isFindTarget = true;
            minTime = min(minTime, current._currentTime);
        }

        for (int i = 0; i < 4; i++)
        {
            int nextRow = current._row + rowDirection[i];
            int nextColumn = current._column + columnDirection[i];

            if (nextRow < 0 or nextRow >= maps.size() or nextColumn < 0 or nextColumn >= maps[0].length())
                continue;
            if (visited[nextRow][nextColumn] or maps[nextRow][nextColumn] == 'X')
                continue;

            _queue.push(Info(nextRow, nextColumn, current._currentTime + 1));
            visited[nextRow][nextColumn] = true;
        }
    }

    if (!isFindTarget)
        return -1;
    return minTime;
}


int FindMinEscapeMazeTime(map<char, pair<int, int>>& labelPositions, const vector<string>& maps)
{
    int result = 0;
    bool isFindTarget = false;
    auto start = labelPositions['S'];
    auto lever = labelPositions['L'];
    auto exit = labelPositions['E'];

    int findingLeverMinTime = CalculateTimeWithBFS(maps, Info(start.first, start.second, 0), Info(lever.first, lever.second, 0), isFindTarget);
    if (findingLeverMinTime == -1)
        return -1;


    isFindTarget = false;
    int findingExitMinTime = CalculateTimeWithBFS(maps, Info(lever.first, lever.second, 0), Info(exit.first, exit.second, 0), isFindTarget);
    if (findingExitMinTime == -1)
        return -1;

    return findingLeverMinTime + findingExitMinTime;
}

int solution(vector<string> maps) {
    map<char, pair<int, int>> labelPositions = GetLabelPositions(maps);
    int answer = FindMinEscapeMazeTime(labelPositions, maps);
    return answer;
}