#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using Square = vector<vector<int>>;
using Line = vector<int>;

void Search(const Square& coloredPaper, vector<int>& counts, int N, int rowBegin, int colBegin)
{
    if (N == 1)
    {
        int color = coloredPaper[rowBegin][colBegin];
        counts[color]++;
        return;
    }

    int color = -1;
    bool isAllEqaul = true;
    for(int row = rowBegin; row < rowBegin + N; row++)
    {
        for (int col = colBegin; col < colBegin + N; col++)
        {
            if (row == rowBegin && col == colBegin)
            {
                color = coloredPaper[row][col];
                continue;
            }

            if (color != coloredPaper[row][col])
            {
                isAllEqaul = false;
                break;
            }
        }

        if (!isAllEqaul)
            break;
    }


    if (color != -1 && isAllEqaul)
    {
        counts[color]++;
        return;
    }

    int next = N / 2;
    Search(coloredPaper, counts, next, rowBegin, colBegin);                 // I
    Search(coloredPaper, counts, next, rowBegin, colBegin + next);          // II
    Search(coloredPaper, counts, next, rowBegin + next, colBegin);          // III
    Search(coloredPaper, counts, next, rowBegin + next, colBegin + next);   // IV
}


int main()
{
    FAST_IO;

    int N;
    cin >> N;

    Square coloredPaper(N, Line(N));
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++)
            cin >> coloredPaper[i][k];

    vector<int> counts { 0, 0 };
    Search(coloredPaper, counts, N, 0, 0);

    for (const auto& color : counts)
        cout << color << "\n";
    return 0;
}
