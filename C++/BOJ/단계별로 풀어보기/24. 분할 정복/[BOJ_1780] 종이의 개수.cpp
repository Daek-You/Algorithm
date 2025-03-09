#include <iostream>
#include <vector>
#include <map>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
const int ALL_NOT_SAME = -2;


int FindNumberInSquare(const vector<vector<int>>& square, int N, int rowBegin, int colBegin)
{
    int number = ALL_NOT_SAME;
    for (int row = rowBegin; row < rowBegin + N; row++)
    {
        for (int col = colBegin; col < colBegin + N; col++)
        {
            if (row == rowBegin and col == colBegin)
            {
                number = square[row][col];
                continue;
            }

            if (square[row][col] != number)
                return ALL_NOT_SAME;
        }
    }

    return number;
}

void Solution(const vector<vector<int>>& paper, map<int, int>& counts, int N, int rowBegin, int colBegin)
{
    if (N == 1)
    {
        int number = paper[rowBegin][colBegin];
        counts[number]++;
        return;
    }

    int number = FindNumberInSquare(paper, N, rowBegin, colBegin);
    if (number != ALL_NOT_SAME)
    {
        counts[number]++;
        return;
    }

    N /= 3;

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            Solution(paper, counts, N, rowBegin + N * row, colBegin + N * col);
}

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int row = 0; row < N; row++)
        for(int col = 0; col < N; col++)
            cin >> paper[row][col];

    map<int, int> answers
    {
        {-1, 0},
        {0,  0},
        {1,  0}
    };


    Solution(paper, answers, N, 0, 0);
    for (const auto& answer : answers)
        cout << answer.second << "\n";
    return 0;
}
