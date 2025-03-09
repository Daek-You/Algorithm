#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

using Point = pair<int, int>;
const int DIRECTION_COUNT = 4;
const char EMPTY = '0';

int DirectionRow[DIRECTION_COUNT] = {-1, 1, 0, 0};
int DirectionCol[DIRECTION_COUNT] = {0, 0, -1, 1};



int FindFieldArea(const vector<string>& map, vector<vector<bool>>& visit, int N, int row, int col) {
    queue<Point> positions;
    positions.emplace(row, col);
    visit[row][col] = true;

    int area = 1;
    while (!positions.empty()) {
        Point current = positions.front();
        positions.pop();

        for (int i = 0; i < DIRECTION_COUNT; i++) {
            int nextRow = current.first + DirectionRow[i];
            int nextCol = current.second + DirectionCol[i];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= N)
                continue;
            
            if (visit[nextRow][nextCol] or map[nextRow][nextCol] == EMPTY)
                continue;
            
            visit[nextRow][nextCol] = true;
            positions.emplace(nextRow, nextCol);
            area++;
        }
    }

    return area;
}

int main() {
    FAST_IO
    int N;
    cin >> N;

    vector<string> map(N);
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
        cin >> map[i];

    vector<int> answers;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (visit[row][col] or map[row][col] == EMPTY)
                continue;
            int area = FindFieldArea(map, visit, N, row, col);
            answers.push_back(area);
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << "\n";

    for (const auto& answer : answers)
        cout << answer << "\n";
    return 0;
}