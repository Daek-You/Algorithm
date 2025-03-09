#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX_INT = 2147483647;
vector<pair<int, int>> directions {{-1, 0}, { 1, 0 }, { 0, -1 }, { 0, 1 }};   // 상, 하, 좌, 우

struct Info
{
    Info(int row, int col, int currentMoveCount) : _row(row), _col(col), _currentMoveCount(currentMoveCount) { }
    int _row;
    int _col;
    int _currentMoveCount;
};


int FindShortestDistance(const vector<string>& board, pair<int, int> current, const pair<int, int>& end) {
    int minCount = MAX_INT;

    queue<Info> myQueue;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].length(), false));
    
    myQueue.push(Info(current.first, current.second, 0));
    visited[current.first][current.second] = true;


    while (!myQueue.empty()) {
        Info current = myQueue.front();
        myQueue.pop();
        bool isArrivalGoal = (current._row == end.first) and (current._col == end.second);

        if (isArrivalGoal)
            minCount = min(minCount, current._currentMoveCount);


        for (int i = 0; i < directions.size(); i++) {

            int nextRow = current._row + directions[i].first;
            int nextCol = current._col + directions[i].second;
            bool isBlocked = nextRow < 0 or nextRow >= board.size() or nextCol < 0 or nextCol >= board[0].length() or board[nextRow][nextCol] == 'D';

            if (isBlocked)
                continue;

            int tempNextRow = nextRow;
            int tempNextCol = nextCol;

            while (true) {
                tempNextRow += directions[i].first;
                tempNextCol += directions[i].second;
                isBlocked = tempNextRow < 0 or tempNextRow >= board.size() or tempNextCol < 0 or tempNextCol >= board[0].length() or board[tempNextRow][tempNextCol] == 'D';

                if (isBlocked)
                    break;
                nextRow += directions[i].first;
                nextCol += directions[i].second;
            }

            if (visited[nextRow][nextCol])
                continue;
            
            myQueue.push(Info(nextRow, nextCol, current._currentMoveCount + 1));
            visited[nextRow][nextCol] = true;
        }
    }

    return minCount;
}


int FindMinMovingCount(const vector<string>& board, map<char, pair<int, int>> symbolPositions) {
    auto currentRobotPosition = symbolPositions['R'];
    auto goal = symbolPositions['G'];

    int answer = FindShortestDistance(board, currentRobotPosition, goal);
    return answer == MAX_INT ? -1 : answer;
}

map<char, pair<int, int>> GetPositions(const vector<string>& board) {
    map<char, pair<int, int>> results;

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].length(); col++) {
            char symbol = '@';

            if (board[row][col] == 'R')
                symbol = 'R';
            else if (board[row][col] == 'G')
                symbol = 'G';

            if (symbol != '@')
                results.insert(make_pair(symbol, make_pair(row, col)));
        }
    }

    return results;
}


int solution(vector<string> board) {
    map<char, pair<int, int>> symbolPositions = GetPositions(board);
    int answer = FindMinMovingCount(board, symbolPositions);

    return answer;
}