#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // 첫 번째 열 그대로 유지
    for (int row = 0; row < rows; row++) {
        dp[row][0] = board[row][0];
        answer = max(answer, dp[row][0]);
    }

    // 첫 번째 행 그대로 유지
    for (int col = 0; col < cols; col++) {
        dp[0][col] = board[0][col];
        answer = max(answer, dp[0][col]);
    }

    // (1, 1)부터 우측 하단까지 검사
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            if (board[row][col] == 1) {
                dp[row][col] = min({ dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1] }) + 1;
                answer = max(answer, dp[row][col]);
            }
        }
    }

    return answer * answer;
}