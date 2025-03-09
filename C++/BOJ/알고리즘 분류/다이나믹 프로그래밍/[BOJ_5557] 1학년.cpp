#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N;
vector<int> Numbers;

void Initialize()
{
    cin >> N;
    Numbers.resize(N);

    for (int i = 0; i < N; i++)
        cin >> Numbers[i];
}

int main()
{
    FAST_IO
    Initialize();

    vector<vector<long long>> dp(N, vector<long long>(21, 0));
    dp[0][Numbers[0]] = 1;

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j] > 0)
            {
                if (j + Numbers[i] <= 20)
                    dp[i][j + Numbers[i]] += dp[i - 1][j];
                if (j - Numbers[i] >= 0)
                    dp[i][j - Numbers[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 2][Numbers[N - 1]];
    return 0;
}
