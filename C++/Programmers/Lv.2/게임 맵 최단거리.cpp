#include <vector>
#include <queue>
using namespace std;
using Position = pair<int, int>;
using Matrix = vector<vector<int>>;
vector<Position> directions { {-1, 0}, { 1, 0 }, { 0, -1 }, { 0, 1 } };                             // 상, 하, 좌, 우


int FindEnemyCampWithMinCount(Matrix& maps, Position player, const Position enemyCamp)        // BFS
{
    int maxRow = maps.size(), maxCol = maps[0].size();
    queue<Position> _queue;
    
    _queue.emplace(player);
    maps[player.first][player.second] = 2;       // 1로 시작하려고 했으나, 1이 갈 수 있는 곳으로 간주 되어서 다 합한 값에서 -1 하겠습니다.
    
    while(!_queue.empty())
    {
        Position current = _queue.front();
        _queue.pop();
        
        for (int i = 0; i < directions.size(); i++)
        {
            int nextRow = current.first + directions[i].first;
            int nextCol = current.second + directions[i].second;
            
            if (nextRow < 0 or nextRow >= maxRow or nextCol < 0 or nextCol >= maxCol)
                continue;
            
            if (maps[nextRow][nextCol] == 0 or maps[nextRow][nextCol] > 1)
                continue;
            
            maps[nextRow][nextCol] = maps[current.first][current.second] + 1;
            _queue.emplace(nextRow, nextCol);
        }
    }
    
    return maps[enemyCamp.first][enemyCamp.second] == 1 ? -1 : maps[enemyCamp.first][enemyCamp.second] - 1;
}

int solution(vector<vector<int>> maps)
{
    Position player(0, 0);
    Position enemyCamp(maps.size() - 1, maps[0].size() - 1);
    
    return FindEnemyCampWithMinCount(maps, player, enemyCamp);
}