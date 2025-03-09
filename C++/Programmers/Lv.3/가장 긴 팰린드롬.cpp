#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int n = s.length();
    if (n == 0) return 0;

    // 2차원 DP 배열 선언 및 초기화
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLength = 1;

    // 길이가 1인 팰린드롬 초기화
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // 길이가 2인 팰린드롬 초기화
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
        }
    }

    // 길이가 3 이상인 팰린드롬 검사
    for (int length = 3; length <= n; ++length) {
        for (int start = 0; start <= n - length; ++start) {
            int end = start + length - 1;
            if (s[start] == s[end] && dp[start + 1][end - 1]) {
                dp[start][end] = true;
                maxLength = length;
            }
        }
    }

    return maxLength;
}
