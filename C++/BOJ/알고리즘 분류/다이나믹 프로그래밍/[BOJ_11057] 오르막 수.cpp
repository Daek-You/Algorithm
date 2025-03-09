#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MOD 10007

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<vector<int>> DP(N + 1, vector<int>(10));
    for (int i = 0; i < 10; i++) DP[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                DP[i][0] = 1;
                continue;
            }

            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % MOD;
        }
    }

    cout << accumulate(DP[N].begin(), DP[N].end(), 0) % MOD;
    return 0;
}