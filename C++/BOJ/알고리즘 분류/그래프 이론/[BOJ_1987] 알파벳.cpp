#include <iostream>
#include <vector>

using namespace std;
using Direction = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define ALPHABET_COUNT 26

vector<Direction> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<bool> Alphabet(ALPHABET_COUNT, false);
int R, C;

void BackTracking(const vector<vector<char>>& field, int& maxStep, int currentStep, int row, int col) {

    for (const auto& direction : Directions) {
        int nextRow = row + direction.first;
        int nextCol = col + direction.second;

        if (nextRow < 0 or nextRow >= R or nextCol < 0 or nextCol >= C) {
            maxStep = max(maxStep, currentStep);
            continue;
        }

        int index = field[nextRow][nextCol] - 'A';
        if (Alphabet[index]) {
            maxStep = max(maxStep, currentStep);
            continue;
        }

        Alphabet[index] = true;
        BackTracking(field, maxStep, currentStep + 1, nextRow, nextCol);
        Alphabet[index] = false;
    }
}

int GetMaximumAlphabet(const vector<vector<char>>& field) {
    int maxStep = 1;
    int index = field[0][0] - 'A';
    
    Alphabet[index] = true;
    BackTracking(field, maxStep, 1, 0, 0);
    return maxStep;
}

int main() {
    FAST_IO

    cin >> R >> C;
    vector<vector<char>> field(R, vector<char>(C));
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            cin >> field[r][c];
    
    int answer = GetMaximumAlphabet(field);
    cout << answer;

    return 0;
}