#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000000;
const int DIGIT_COUNT = 10;
const int BUFFER_COUNT = 2;

void Swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int N;
    cin >> N;

    /*
             0 1 2 3 4 5 6 7 8 9
        N:1  0 1 1 1 1 1 1 1 1 1
        N:2  1 1 2 2 2 2 2 2 2 1
        N:3  1 3 3 4 4 4 4 4 3 2
        N:4  ...
        --------------------------------
        - dp[N][0] = dp[N-1][1]
        - dp[N][i] = dp[N-1][i-1] + dp[N-1][i+1];    (i > 0 and i < 9)
        - dp[N][9] = dp[N-1][8]
    */

    // 1. 초기화
    vector<vector<int>> dp(BUFFER_COUNT, vector<int>(DIGIT_COUNT));
    int writeBufferIndex = 0, readBufferIndex = 1;
    int sum = 9;

    for (int i = 1; i < DIGIT_COUNT; i++)
        dp[writeBufferIndex][i] = 1;
    // ------------------------------------


    // 2. 로직
    Swap(writeBufferIndex, readBufferIndex);
    for (int i = 1; i < N; i++)
    {
        sum = 0;

        for (int j = 0; j < DIGIT_COUNT; j++)
        {
            if (j == 0 or j == 9)
            {
                int targetIndex = (j == 0) ? j + 1 : j - 1;
                int newValue = dp[readBufferIndex][targetIndex];

                dp[writeBufferIndex][j] = newValue;
                sum = (sum + newValue) % MOD;
                continue;
            }

            dp[writeBufferIndex][j] = (dp[readBufferIndex][j - 1] + dp[readBufferIndex][j + 1]) % MOD;
            sum = (sum + dp[writeBufferIndex][j]) % MOD;
        }

        Swap(writeBufferIndex, readBufferIndex);
    }

    cout << sum;
    return 0;
}