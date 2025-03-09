#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

using Point = pair<int, int>;
const int EMPTY = 0;
const int CABBAGE = 1;
const int DIRECTION_COUNT = 4;

int dx[DIRECTION_COUNT] = {-1, 1, 0, 0};
int dy[DIRECTION_COUNT] = {0, 0, -1, 1};

void SetEarthworm(const vector<vector<int>>& field, vector<vector<bool>>& visit, int M, int N, int row, int col) {
    queue<Point> positions;
    positions.emplace(row, col);
    visit[row][col] = true;

    while (!positions.empty()) {
        Point current = positions.front();
        positions.pop();

        for (int i = 0; i < DIRECTION_COUNT; i++) {
            int nextRow = current.first + dx[i];
            int nextCol = current.second + dy[i];
            
            if (nextRow < 0 or nextRow >= M or nextCol < 0 or nextCol >= N)
                continue;
            
            if (visit[nextRow][nextCol] or field[nextRow][nextCol] == EMPTY)
                continue;
            
            positions.emplace(nextRow, nextCol);
            visit[nextRow][nextCol] = true;
        }
    }
}

int main() {
    FAST_IO
    int T, M, N, K;
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        vector<vector<int>> field(M, vector<int>(N, EMPTY));
        for (int i = 0; i < K; i++) {
            int row, col;
            cin >> row >> col;
            field[row][col] = CABBAGE;
        }

        vector<vector<bool>> visit(M, vector<bool>(N, false));
        int answer = 0;
        for (int row = 0; row < M; row++) {
            for (int col = 0; col < N; col++) {
                if (visit[row][col] or field[row][col] == EMPTY)
                    continue;
                SetEarthworm(field, visit, M, N, row, col);
                answer++;
            }
        }

        cout << answer << "\n";
    }    

    return 0;
}