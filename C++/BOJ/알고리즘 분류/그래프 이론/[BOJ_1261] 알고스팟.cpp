#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
using Direction = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define EMPTY 0
#define WALL 1
#define MAX 1000000000
vector<Direction> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // 상 하 좌 우

struct Data {
    Data() { }
    Data(int row, int col, int count) :
    row(row), col(col), brokenCount(count) { }

    bool operator<(const Data& other) const { return brokenCount > other.brokenCount; }
    int row, col, brokenCount;
};


void Dijkstra(const vector<vector<bool>>& field, vector<vector<int>>& counts, int N, int M, int row, int col) {
    priority_queue<Data> pq;
    pq.emplace(row, col, 0);
    counts[row][col] = 0;

    while (!pq.empty()) {
        row = pq.top().row;
        col = pq.top().col;
        int brokenCount = pq.top().brokenCount;
        pq.pop();

        if (counts[row][col] < brokenCount)
            continue;

        for (const auto& adjacentDirection : Directions) {
            int nextRow = row + adjacentDirection.first;
            int nextCol = col + adjacentDirection.second;

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
                continue;

            bool isWall = field[nextRow][nextCol];
            int currentCost = brokenCount + isWall;

            if (currentCost < counts[nextRow][nextCol]) {
                counts[nextRow][nextCol] = currentCost;
                pq.emplace(nextRow, nextCol, currentCost);
            }
        }
    }
}

int main() {
    FAST_IO
    int M, N;
    cin >> M >> N;

    vector<vector<bool>> field(N, vector<bool>(M));
    for (int row = 0; row < N; row++) {
        string line;
        cin >> line;

        for (int col = 0; col < M; col++)
            field[row][col] = line[col] - '0';
    }

    vector<vector<int>> brokenWallCounts(N, vector<int>(M, MAX));
    Dijkstra(field, brokenWallCounts, N, M, 0, 0);

    cout << brokenWallCounts[N - 1][M - 1];
    return 0;
}