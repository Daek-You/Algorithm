#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


const int BLANK = 0;
const int N = 9;
vector<vector<int>>     SudokuBoard;
vector<vector<bool>>    CheckingForRow, CheckingForColumn, CheckingForSquare;


int GetIndexOfSquare(const int row, const int column)
{
    /*  사각형 영역별 번호 (각 영역은 3x3 크기)
        000 111 222
        000 111 222
        000 111 222
        
        333 444 555
        333 444 555
        333 444 555

        666 777 888
        666 777 888
        666 777 888
    */

    return (row / 3) * 3 + (column / 3);
}

void Initialize()
{
    SudokuBoard.resize(N, vector<int>(N));
    CheckingForRow.resize(N, vector<bool>(N, false));
    CheckingForColumn.resize(N, vector<bool>(N, false));
    CheckingForSquare.resize(N, vector<bool>(N, false));

    for (int r = 0; r < N; r++)
    {
        string rowLine;
        cin >> rowLine;

        for (int c = 0; c < N; c++)
        {
            int value = rowLine[c] - '0';
            SudokuBoard[r][c] = value;

            if (value != BLANK)
            {
                CheckingForRow[r][value] = true;
                CheckingForColumn[c][value] = true;
                CheckingForSquare[GetIndexOfSquare(r, c)][value] = true;
            }
        }
    }
}

void Print()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
            cout << SudokuBoard[r][c];
        cout << "\n";
    }
}

void Backtracking(int index)
{
    if (index == N * N)
    {
        Print();
        exit(0);
    }

    int row = index / N;
    int column = index % N;

    if (SudokuBoard[row][column] == BLANK)
    {
        for (int value = 1; value <= N; value++)
        {
            if (!CheckingForRow[row][value] and !CheckingForColumn[column][value] and !CheckingForSquare[GetIndexOfSquare(row, column)][value])
            {
                SudokuBoard[row][column] = value;
                CheckingForRow[row][value] = true;
                CheckingForColumn[column][value] = true;
                CheckingForSquare[GetIndexOfSquare(row, column)][value] = true;

                Backtracking(index + 1);

                SudokuBoard[row][column] = BLANK;
                CheckingForRow[row][value] = false;
                CheckingForColumn[column][value] = false;
                CheckingForSquare[GetIndexOfSquare(row, column)][value] = false;
            }
        }
    }

    else
        Backtracking(index + 1);
}

int main()
{
    FAST_IO
    Initialize();
    Backtracking(0);

    return 0;
}
