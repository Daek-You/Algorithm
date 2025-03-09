#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using Board = vector<vector<int>>;
const char WHITE_COLOR = 'W';
const char BLACK_COLOR = 'B';

bool ShouldChangeColor(const char startColor, const char inputColor, const int row, const int col)
{
    bool isEven = (row + col) % 2 == 0;

    // (행 + 열)이 짝수라면, 시작 색(1, 1)과 같아야 올바른 보드판이 된다.
    if (isEven && startColor == inputColor)
        return false;

    // (행 + 열)이 홀수라면, 시작 색(1, 1)과 달라야 올바른 보드판이 된다.
    else if (!isEven && startColor != inputColor)
        return false;
    return true;
}

int main()
{
    FAST_IO;

    int N, M, K;
    cin >> N >> M >> K;

    Board whiteStartBoard(N + 1, vector<int>(M + 1));
    Board blackStartBoard(N + 1, vector<int>(M + 1));

    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= M; col++)
        {
            char color;
            cin >> color;

            bool isChangedInWhiteBoard = ShouldChangeColor(WHITE_COLOR, color, row, col);
            bool isChangedInBlackBoard = ShouldChangeColor(BLACK_COLOR, color, row, col);

            // 이전 누적합 + 새로운 값
            whiteStartBoard[row][col] = whiteStartBoard[row - 1][col] + whiteStartBoard[row][col - 1] - whiteStartBoard[row - 1][col - 1] + isChangedInWhiteBoard;
            blackStartBoard[row][col] = blackStartBoard[row - 1][col] + blackStartBoard[row][col - 1] - blackStartBoard[row - 1][col - 1] + isChangedInBlackBoard;
        }
    }

    int answerInWhiteBoard = 1000000000;
    int answerInBlackBoard = 1000000000;

    for (int row = K; row <= N; row++)
    {
        for (int col = K; col <= M; col++)
        {
            int minInWhiteBoard = whiteStartBoard[row][col] - whiteStartBoard[row - K][col] - whiteStartBoard[row][col - K] + whiteStartBoard[row - K][col - K];
            int minInBlackBoard = blackStartBoard[row][col] - blackStartBoard[row - K][col] - blackStartBoard[row][col - K] + blackStartBoard[row - K][col - K];

            answerInWhiteBoard = min(answerInWhiteBoard, minInWhiteBoard);
            answerInBlackBoard = min(answerInBlackBoard, minInBlackBoard);
        }
    }

    cout << min(answerInWhiteBoard, answerInBlackBoard);
    return 0;
}