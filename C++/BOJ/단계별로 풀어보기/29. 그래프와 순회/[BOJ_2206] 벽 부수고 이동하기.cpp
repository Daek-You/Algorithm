#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
using Cube = vector<vector<vector<bool>>>;

int BFS(vector<vector<int>>&, Cube&, int, int);
void Input(vector<vector<int>>&, int, int);
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
/* -------------------------------------------------------------------------*/

vector<vector<int>> Directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const int ROUTE = 0;
const int WALL = 1;

struct Block {
    Block() { }
    Block(int r, int c, int count, bool h) :
        row(r), col(c), distance(count), hasDestroyedWall(h) { }

    int row, col;
    int distance;
    bool hasDestroyedWall;
};

// Queue를 통해 관리하는 걸로 했네?

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<vector<int>> field(N, vector<int>(M));
    Input(field, N, M);

    Cube visit(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    int answer = BFS(field, visit, N, M);
    cout << answer; 
    return 0;
}

void Input(vector<vector<int>>& field, int N, int M) {
    for (int row = 0; row < N; row++) {
    string line;
    cin >> line;

    for (int col = 0; col < M; col++)
        field[row][col] = line[col] - '0';
    }
}

int BFS(vector<vector<int>>& field, Cube& visit, int N, int M) {
    queue<Block> blocks;
    blocks.emplace(0, 0, 1, false);
    visit[0][0][0] = true;

    while (!blocks.empty()) {
        Block current = blocks.front();
        blocks.pop();

        int row = current.row, col = current.col;
        int distance = current.distance;
        bool broken = current.hasDestroyedWall;
        
        if (row == N - 1 and col == M - 1)
            return distance;

        for (int i = 0; i < Directions.size(); i++) {
            int nextRow = row + Directions[i][0];
            int nextCol = col + Directions[i][1];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
                continue;

            if (field[nextRow][nextCol] == WALL and !broken) {
                visit[nextRow][nextCol][1] = true;
                blocks.emplace(nextRow, nextCol, distance + 1, true);
            }

            else if (field[nextRow][nextCol] == ROUTE and !visit[nextRow][nextCol][broken]) {
                visit[nextRow][nextCol][broken] = true;
                blocks.emplace(nextRow, nextCol, distance + 1, broken);
            }
        }
    }
    
    return -1;
}