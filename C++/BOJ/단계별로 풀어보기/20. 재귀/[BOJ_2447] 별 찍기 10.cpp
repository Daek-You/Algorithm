#include <iostream>
using namespace std;

/*
    재귀를 너무 어렵게 생각하고 있나 내가
*/

void MakeStar(int n, int row, int column)
{
    if ((row / n) % 3 == 1 and (column / n) % 3 == 1)
    {
        cout << ' ';
        return;
    }

    if (n / 3 == 0)
    {
        cout << '*';
        return;
    }

    MakeStar(n / 3, row, column);
}

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            MakeStar(N, i, j);
        cout << '\n';
    }

    return 0;
}