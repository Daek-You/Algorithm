#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cout.tie(NULL);              \
    cin.tie(NULL);


using Point = pair<int, int>;
const int WALL = 0;
const int DIRECTION_COUNT = 4;

int dx[DIRECTION_COUNT] = {-1, 1, 0, 0};
int dy[DIRECTION_COUNT] = {0, 0, -1, 1};


int FindShortestRoute(vector<vector<int>>& map, int N, int M, int row, int col)
{
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    queue<Point> positions;

    positions.emplace(row, col);
    visit[row][col] = true;

    while (!positions.empty())
    {
        Point current = positions.front();
        positions.pop();

        for (int i = 0; i < DIRECTION_COUNT; i++)
        {
            int nextRow = current.first + dx[i];
            int nextCol = current.second + dy[i];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
                continue;

            if (map[nextRow][nextCol] == WALL)
                continue;

            if (visit[nextRow][nextCol])
                continue;

            visit[nextRow][nextCol] = true;
            positions.emplace(nextRow, nextCol);
            map[nextRow][nextCol] = map[current.first][current.second] + 1;
        }
    }

    return map[N - 1][M - 1];
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M, WALL));
    for (int row = 0; row < N; row++) {
        string line;
        cin >> line;

        for (int col = 0; col < M; col++) {
            int value = line[col] - '0';
            maze[row][col] = value;
        }
    }

    int answer = FindShortestRoute(maze, N, M, 0, 0);
    cout << answer;

    return 0;
}