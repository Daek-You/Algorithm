#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); std::cout.tie(NULL); std::cin.tie(NULL);

using Point = pair<int, int>;
vector<vector<int>> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // 상, 하, 좌, 우

const int EMPTY = -1;
const int UNRIPED_TOMATO = 0;
const int RIPED_TOMATO = 1;

struct Tomato {
    Tomato() { }
    Tomato(int r, int c, int d) : row(r), col(c), day(d) { }
    int row, col, day;
};

int GetResultOfRipeningTomatoes(vector<vector<int>>& box, queue<Tomato>& ripedTomatoes, int unripedTomatoes ,int maxRow, int maxCol) {
    if (unripedTomatoes == 0)
        return 0;

    int day = 0;

    while (!ripedTomatoes.empty()) {
        Tomato current = ripedTomatoes.front();
        ripedTomatoes.pop();
        
        for (int i = 0; i < Directions.size(); i++) {
            int nextRow = current.row + Directions[i][0];
            int nextCol = current.col + Directions[i][1];

            if (nextRow < 0 or nextRow >= maxRow or nextCol < 0 or nextCol >= maxCol)
                continue;
            if (box[nextRow][nextCol] == EMPTY or box[nextRow][nextCol] == RIPED_TOMATO)
                continue;
            
            box[nextRow][nextCol] = RIPED_TOMATO;
            ripedTomatoes.emplace(nextRow, nextCol, current.day + 1);
            day = current.day + 1;
            unripedTomatoes--;
        }
    }

    return unripedTomatoes == 0 ? day : -1;
}

int main() {
    FAST_IO
    int maxCol, maxRow;
    cin >> maxCol >> maxRow;

    vector<vector<int>> box(maxRow, vector<int>(maxCol));
    queue<Tomato> positions;
    int unripedTomatoes = 0;

    for (int row = 0; row < maxRow; row++) {
        for (int col = 0; col < maxCol; col++) {
            cin >> box[row][col];

            if (box[row][col] == RIPED_TOMATO)      positions.emplace(row, col, 0);
            if (box[row][col] == UNRIPED_TOMATO)    unripedTomatoes++;
        }
    }

    int answer = GetResultOfRipeningTomatoes(box, positions, unripedTomatoes, maxRow, maxCol);
    cout << answer;
    return 0;
}