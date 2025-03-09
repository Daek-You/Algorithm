#include <vector>
using namespace std;
const int DIVISOR = 1000000007;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIVISOR;
    return dp[n];
}