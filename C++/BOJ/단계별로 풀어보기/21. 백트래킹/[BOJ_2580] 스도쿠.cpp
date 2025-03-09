#include <iostream>
#include <vector>
using namespace std;
using Point = pair<int, int>;
const int BOARD_SIZE = 9;

class Sudoku
{
public:
    Sudoku();
    void StartGame();

private:
    void Show();
    void Fill(int i);
    bool IsAvailablePlacement(int row, int col);

private:
    vector<vector<int>> board;
    vector<Point> blanks;
    int blankCount = 0;
    bool isGameDone = false;
};

Sudoku::Sudoku()
{
    board.resize(BOARD_SIZE);
    for (int i = 0; i < board.size(); i++)
        board[i].resize(BOARD_SIZE);

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cin >> board[row][col];

            if (board[row][col] == 0)
            {
                blankCount++;
                blanks.emplace_back(row, col);
            }
        }
    }
}

void Sudoku::StartGame()
{
    Fill(0);
}

void Sudoku::Fill(int i)
{
    if (i == blankCount)
    {
        Show();
        isGameDone = true;
        return;
    }

    int row = blanks[i].first;
    int col = blanks[i].second;

    for (int num = 1; num <= 9; num++)
    {
        board[row][col] = num;

        if (IsAvailablePlacement(row, col))
            Fill(i + 1);
        if (isGameDone)
            return;
    }

    board[row][col] = 0;
}

void Sudoku::Show()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool Sudoku::IsAvailablePlacement(int row, int col)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        bool isEqaulNumberInRow = (board[row][i] == board[row][col] && i != col);
        bool isEqaulNumberInCol = (board[i][col] == board[row][col] && i != row);

        if (isEqaulNumberInRow || isEqaulNumberInCol)
            return false;
    }

    int sectorRow = row / 3;
    int sectorCol = col / 3;

    for (int r = 3 * sectorRow; r < 3 * sectorRow + 3; r++)
    {
        for (int c = 3 * sectorCol; c < 3 * sectorCol + 3; c++)
        {
            bool isEqaulNumberInSqaure = (board[r][c] == board[row][col] && r != row && c != col);

            if (isEqaulNumberInSqaure)
                return false;
        }
    }

    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    Sudoku sudoku;
    sudoku.StartGame();
    return 0;
}