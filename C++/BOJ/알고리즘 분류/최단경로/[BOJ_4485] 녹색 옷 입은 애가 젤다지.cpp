#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 1000000000

vector<pair<int, int>> Directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   // 상하좌우

struct Data {
    Data() { }
    Data(int row, int col, int cost) : row(row), col(col), cost(cost) { }
    bool operator<(const Data& other) const { return cost > other.cost; }
    int row, col, cost;
};

int Dijkstra(const vector<vector<int>>& maze, const int N, int startRow, int startCol) {
    vector<vector<int>> costs(N, vector<int>(N, MAX));
    priority_queue<Data> pq;

    costs[startRow][startCol] = maze[startRow][startCol];
    pq.emplace(startRow, startCol, maze[startRow][startCol]);

    while (!pq.empty()) {
        int row = pq.top().row;
        int col = pq.top().col;
        int cost = pq.top().cost;
        pq.pop();

        if (costs[row][col] < cost)
            continue;
        
        for (const auto& direction : Directions) {
            int nextRow = row + direction.first;
            int nextCol = col + direction.second;
            
            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= N)
                continue;
            
            int nextCost = cost + maze[nextRow][nextCol];
            if (nextCost < costs[nextRow][nextCol]) {
                costs[nextRow][nextCol] = nextCost;
                pq.emplace(nextRow, nextCol, nextCost);
            }
        }
    }
    
    return costs[N - 1][N - 1];
}

int main() {
    FAST_IO
    int N, testCastNumber = 1;

    while (true) {
        cin >> N;

        if (N == 0)
            break;
        
        vector<vector<int>> maze(N, vector<int>(N));
        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++)
                cin >> maze[row][col];
        
        int answer = Dijkstra(maze, N, 0, 0);
        cout << "Problem " << testCastNumber++ << ": " << answer << "\n";
    }

    return 0;
}