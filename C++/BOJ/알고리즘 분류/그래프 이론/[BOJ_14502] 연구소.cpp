#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using Matrix = vector<vector<int>>;
using Position = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define MAX_WALL_COUNT 3

vector<vector<int>> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<Position> VirusPositions;
int N, M;


int GetSafeArea(const Matrix& field) {
    int area = 0;
    for (const auto& line : field) {
        for (const auto& element : line) {
            if (element == EMPTY)
                area++;
        }
    }

    return area;
}

int BFS(Matrix& field) {
    queue<Position> positions;
    for (const auto& virusPos : VirusPositions)
        positions.emplace(virusPos.first, virusPos.second);

    stack<Position> back;
    while (!positions.empty()) {
        int currentRow = positions.front().first;
        int currentCol = positions.front().second;
        positions.pop();

        for (const auto& direction : Directions) {
            int nextRow = currentRow + direction[0];
            int nextCol = currentCol + direction[1];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
                continue;
            if (field[nextRow][nextCol] != EMPTY)
                continue;
            
            field[nextRow][nextCol] = VIRUS;
            positions.emplace(nextRow, nextCol);
            back.emplace(nextRow, nextCol);
        }
    }

    int safeArea = GetSafeArea(field);

    while (!back.empty()) {
        int row = back.top().first;
        int col = back.top().second;
        
        back.pop();
        field[row][col] = EMPTY;
    }

    return safeArea;
}

void BackTracking(Matrix& field, vector<Position>& newWalls, int& safeArea, int row, int col) {
    if (newWalls.size() == MAX_WALL_COUNT) {
        int newResult = BFS(field);
        safeArea = max(safeArea, newResult);
        return;
    }

    int c;
    for (int r = row; r < N; r++) {
        // 열이 바뀌면 다시 열 초기화
        c = (c >= M) ? 0 : col;
        for (; c < M; c++) {
            if (field[r][c] == WALL or field[r][c] == VIRUS)
                continue;
            
            field[r][c] = WALL;
            newWalls.emplace_back(r, c);

            BackTracking(field, newWalls, safeArea, r, c + 1);

            field[r][c] = EMPTY;
            newWalls.pop_back();
        }
    }
}

int StartSimulation(Matrix& field) {
    int safeArea = 0;
    vector<Position> newWallPositions;

    BackTracking(field, newWallPositions, safeArea, 0, 0);
    return safeArea;
} 

int main() {
    FAST_IO
    cin >> N >> M;

    Matrix field(N, vector<int>(M));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> field[row][col];

            if (field[row][col] == VIRUS)
                VirusPositions.emplace_back(row, col);
        }
    }
    
    int answer = StartSimulation(field);
    cout << answer;

    return 0;
}