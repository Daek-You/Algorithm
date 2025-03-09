#include <vector>
using namespace std;

// 역시 카카오는 대단한 사람들밖에 없는 것 같다. 한 수 배웠습니다.
// https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int N = board.size(), M = board[0].size();
    vector<vector<int>> field(N + 1, vector<int>(M + 1, 0));

    for (const auto& content : skill) {
        int row1 = content[1], col1 = content[2];
        int row2 = content[3], col2 = content[4];
        int degree = (content[0] == 1) ? -content[5] : content[5];

        field[row1][col1] += degree;
        field[row1][col2 + 1] -= degree;
        field[row2 + 1][col1] -= degree;
        field[row2 + 1][col2 + 1] += degree;
    }

    for (int col = 0; col < M; col++)
        for (int row = 1; row < N; row++)
            field[row][col] += field[row - 1][col];
    
    for (int row = 0; row < N; row++)
        for (int col = 1; col < M; col++)
            field[row][col] += field[row][col - 1];
    
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            board[row][col] += field[row][col];
    
    int answer = 0;
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            if (board[row][col] > 0)
                answer++;

    return answer;
}