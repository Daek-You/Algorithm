#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); std::cout.tie(NULL); std::cin.tie(NULL);

using Matrix = vector<vector<vector<int>>>;

vector<vector<int>> Directions { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };  // 위, 아래, 앞, 뒤, 좌, 우
const int EMPTY = -1;
const int UNRIPED_TOMATO = 0;
const int RIPED_TOMATO = 1;

struct Tomato {
    Tomato() { }
    Tomato(int h, int r, int c, int d) : height(h), row(r), col(c), day(d) { }
    int height, row, col, day;
};

int GetResultOfRipeningTomatoes(Matrix& box, queue<Tomato>& ripedTomatoes, int unripedTomatoes, int maxHeight, int maxRow, int maxCol) {
    if (unripedTomatoes == 0)
        return 0;

    int day = 0;

    while (!ripedTomatoes.empty()) {
        Tomato current = ripedTomatoes.front();
        ripedTomatoes.pop();
        
        for (int i = 0; i < Directions.size(); i++) {
            int nH = current.height + Directions[i][0];
            int nR = current.row + Directions[i][1];
            int nC = current.col + Directions[i][2];

            if (nH < 0 or nH >= maxHeight or nR < 0 or nR >= maxRow or nC < 0 or nC >= maxCol)
                continue;
            
            if (box[nH][nR][nC] == EMPTY or box[nH][nR][nC] == RIPED_TOMATO)
                continue;
            
            box[nH][nR][nC] = RIPED_TOMATO;
            ripedTomatoes.emplace(nH, nR, nC, current.day + 1);
            day = current.day + 1;
            unripedTomatoes--;
        }
    }

    return unripedTomatoes == 0 ? day : -1;
}

int main() {
    FAST_IO
    int maxCol, maxRow, maxHeight;
    cin >> maxCol >> maxRow >> maxHeight;

    Matrix box(maxHeight, vector<vector<int>>(maxRow, vector<int>(maxCol)));
    queue<Tomato> positions;
    int unripedTomatoes = 0;

    for (int h = maxHeight - 1; h >= 0; h--) {
        for (int r = 0; r < maxRow; r++) { 
            for (int c = 0; c < maxCol; c++) {
                cin >> box[h][r][c];

                if (box[h][r][c] == RIPED_TOMATO)   positions.emplace(h, r, c, 0);
                if (box[h][r][c] == UNRIPED_TOMATO) unripedTomatoes++;
            }
        }
    }

    int answer = GetResultOfRipeningTomatoes(box, positions, unripedTomatoes, maxHeight, maxRow, maxCol);
    cout << answer;
    return 0;
}