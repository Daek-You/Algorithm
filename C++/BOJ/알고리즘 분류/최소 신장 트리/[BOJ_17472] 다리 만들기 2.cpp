#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

using Position = pair<int, int>;    // <행, 열>
using Data = pair<int, int>;        // <거리, 섬 번호>

vector<vector<int>> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // 상하좌우

const int SEA = 0;
const int MAX = 100000000;
int N, M;


void Input(vector<vector<int>>& field);
void SetIsland(vector<vector<int>>& field, int& islandNumber);
void BFS(vector<vector<int>>& field, const int islandNumber, int row, int col);
void GetIslandDistances(const vector<vector<int>>& field, vector<vector<int>>& distances);
void DFS(const vector<vector<int>>& field, vector<vector<int>>& distances, const vector<int>& direction, int islandNumber, int row, int col, int distance);
int Prim(const vector<vector<int>>& distances, int start);

int main() {
    FAST_IO
    cin >> N >> M;

    int islandNumber = 1;
    vector<vector<int>> field(N, vector<int>(M));
    
    Input(field);
    SetIsland(field, islandNumber);

    vector<vector<int>> distances(islandNumber, vector<int>(islandNumber, MAX));
    GetIslandDistances(field, distances);

    int answer = Prim(distances, 1);
    cout << answer;
    return 0;
}

int Prim(const vector<vector<int>>& distances, int start) {
    vector<bool> MST(distances.size(), false);
    MST[start] = true;

    priority_queue<Data, vector<Data>, greater<Data>> edges;
    for (int i = 1; i < distances[start].size(); i++) {
        if (i == start or distances[start][i] == MAX)
            continue;
        edges.emplace(distances[start][i], i);
    }

    int answer = 0;
    while (!edges.empty()) {
        int distance = edges.top().first;
        int islandNumber = edges.top().second;
        edges.pop();

        if (MST[islandNumber])
            continue;
        
        MST[islandNumber] = true;
        answer += distance;

        for (int i = 1; i < distances[islandNumber].size(); i++) {
            if (i == islandNumber or MST[i] or distances[islandNumber][i] == MAX)
                continue;
            edges.emplace(distances[islandNumber][i], i);
        }
    }

    for (int i = 1; i < MST.size(); i++)
        if (!MST[i])
            return -1;
    return answer;
}


void DFS(const vector<vector<int>>& field, vector<vector<int>>& distances, const vector<int>& direction, int islandNumber, int row, int col, int distance) {
    int nextRow = row + direction[0];
    int nextCol = col + direction[1];

    if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
        return;
    if (field[nextRow][nextCol] == islandNumber)
        return;
    if (field[nextRow][nextCol] == SEA) {
        DFS(field, distances, direction, islandNumber, nextRow, nextCol, distance + 1);
        return;
    }

    if (distance <= 1)
        return;

    int otherIslandNumber = field[nextRow][nextCol];
    int newDistance = min(distance, distances[islandNumber][otherIslandNumber]);

    distances[islandNumber][otherIslandNumber] = newDistance;
    distances[otherIslandNumber][islandNumber] = newDistance;
}

void GetIslandDistances(const vector<vector<int>>& field, vector<vector<int>>& distances) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (field[row][col] == SEA)
                continue;
            
            for (const auto& direction : Directions)
                DFS(field, distances, direction, field[row][col], row, col, 0);
        }
    }
}

void Input(vector<vector<int>>& field) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++) {
            int value;
            cin >> value;

            value = (value == 1) ? MAX : value;
            field[row][col] = value;
        }
}

void SetIsland(vector<vector<int>>& field, int& islandNumber) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (field[row][col] == SEA or field[row][col] < islandNumber)
                continue;
            BFS(field, islandNumber++, row, col);
        }
    }
}

void BFS(vector<vector<int>>& field, const int islandNumber, int row, int col) {
    queue<Position> positions;
    positions.emplace(row, col);
    field[row][col] = islandNumber;

    while (!positions.empty()) {
        int currentRow = positions.front().first;
        int currentCol = positions.front().second;
        positions.pop();

        for (const auto& direction : Directions) {
            int nextRow = currentRow + direction[0];
            int nextCol = currentCol + direction[1];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= M)
                continue;
            if (field[nextRow][nextCol] == SEA or field[nextRow][nextCol] == islandNumber)
                continue;
            
            field[nextRow][nextCol] = islandNumber;
            positions.emplace(nextRow, nextCol);
        }
    }
}