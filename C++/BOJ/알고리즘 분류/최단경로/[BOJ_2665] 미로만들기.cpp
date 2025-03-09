#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000
#define BLACK_ROOM 0
#define WHITE_ROOM 1

vector<pair<int, int>> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Block
{
    Block() { }
    Block(int row, int col, int wallCount) :
          row(row), col(col), brokenWallCount(wallCount) { }
    
    bool operator<(const Block& other) const { return brokenWallCount > other.brokenWallCount; }
    int row, col, brokenWallCount;
};

int Dijkstra(const vector<vector<bool>>& field, int n)
{
    vector<vector<int>> brokenWalls(n, vector<int>(n, INF));
    priority_queue<Block> blocks;

    brokenWalls[0][0] = 0;
    blocks.emplace(0, 0, 0);

    while (!blocks.empty())
    {
        Block block = blocks.top();
        blocks.pop();

        int currentRow = block.row; 
        int currentCol = block.col;
        int currentBrokenWallCount = block.brokenWallCount;

        for (const auto& direction : Directions)
        {
            int nextRow = currentRow + direction.first;
            int nextCol = currentCol + direction.second;
            
            if (nextRow < 0 or nextRow >= n or nextCol < 0 or nextCol >= n)
                continue;

            bool willBreak = (field[nextRow][nextCol] == BLACK_ROOM); 
            int newBrokenWallCount = currentBrokenWallCount + willBreak;

            if (newBrokenWallCount < brokenWalls[nextRow][nextCol])
            {
                brokenWalls[nextRow][nextCol] = newBrokenWallCount;
                blocks.emplace(nextRow, nextCol, newBrokenWallCount);
            }
        }
    }

    bool isAlived = brokenWalls[n - 1][n - 1] != INF;
    return isAlived ? brokenWalls[n - 1][n - 1] : 0;
}

int main() {
    FAST_IO
    int n;
    cin >> n;

    vector<vector<bool>> field(n, vector<bool>(n));
    for (int row = 0; row < n; row++)
    {
        string line;
        cin >> line;
        
        for (int col = 0; col < n; col++)
            field[row][col] = line[col] - '0';
    }

    int answer = Dijkstra(field, n);
    cout << answer;

    return 0;
}