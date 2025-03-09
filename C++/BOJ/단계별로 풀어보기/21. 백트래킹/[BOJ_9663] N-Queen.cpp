#include <iostream>
#include <vector>
using namespace std;

bool CheckQueenExisting(vector<vector<bool>>& chessBoard, int row, int column) {
    for (int i = 0; i < row; i++) {
        if (chessBoard[i][column])     // 맨 위 행부터 현재 행까지 같은 열에 퀸 있는지 검사
            return true;

        int colDiff = row - i;
        if (column - colDiff >= 0 && chessBoard[i][column - colDiff])  // 왼쪽 위 대각선 검사
            return true;

        if (column + colDiff < chessBoard.size() && chessBoard[i][column + colDiff])  // 오른쪽 위 대각선 검사
            return true;
    }
    return false;
}

int NQueen(vector<vector<bool>>& chessBoard, int currentRow) {
    if (currentRow == chessBoard.size())
        return 1;

    int answer = 0;
    for (int column = 0; column < chessBoard.size(); column++) {
        if (!CheckQueenExisting(chessBoard, currentRow, column)) {
            chessBoard[currentRow][column] = true;
            answer += NQueen(chessBoard, currentRow + 1);
            chessBoard[currentRow][column] = false;
        }
    }
    return answer;
}
//  0 1 2 3 4
//0 _ _ * _ _ 
//1 _ _ _ _ _
//2 _ _ _ * _

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<bool>> chessBoard(N, vector<bool>(N, false));
    cout << NQueen(chessBoard, 0);
    return 0;
}
