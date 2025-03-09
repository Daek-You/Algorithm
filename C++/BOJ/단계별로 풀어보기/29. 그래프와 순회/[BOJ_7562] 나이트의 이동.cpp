#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

using Point = pair<int, int>;
vector<vector<int>> Directions { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

int main() {
    FAST_IO
    int T, L;
    cin >> T;

    while (T--) {
        cin >> L;

        vector<vector<int>> field(L, vector<int>(L));
        queue<Point> positions;

        int startRow, startCol, destRow, destCol;
        cin >> startRow >> startCol;
        cin >> destRow >> destCol;

        positions.emplace(startRow, startCol);
        field[startRow][startCol] = 1;

        while (!positions.empty()) {
            Point current = positions.front();
            positions.pop();

            if (current.first == destRow and current.second == destCol)
                break;

            for (int i = 0; i < Directions.size(); i++) {
                int nextRow = current.first + Directions[i][0];
                int nextCol = current.second + Directions[i][1];

                if (nextRow < 0 or nextRow >= L or nextCol < 0 or nextCol >= L)
                    continue;
                
                if (field[nextRow][nextCol])
                    continue;
                
                positions.emplace(nextRow, nextCol);
                field[nextRow][nextCol] = field[current.first][current.second] + 1;
            }
        }

        int answer = field[destRow][destCol] - (field[destRow][destCol] != 0); 
        cout << answer << "\n";
    }

    return 0;
}