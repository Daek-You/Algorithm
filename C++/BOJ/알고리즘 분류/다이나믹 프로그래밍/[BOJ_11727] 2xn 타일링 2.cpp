#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MOD 10007

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> dp(N);
    dp[0] = 1, dp[1] = 3;

    /*
        n번째에 타일이 놓여지는 경우는 다음과 같다.
        1) n - 1번까지 타일을 채운 다음, 1x2 타일을 1개 놓는 경우
        2) n - 2번까지 타일을 채운 다음, 2x1 타일을 2개 놓는 경우
        3) n - 2번까지 타일을 채운 다음, 2x2 타일을 1개 놓은 경우

        여기서 2, 3번은 어차피 같은 영역에 놓이는 경우의 수라 두 번 더하는 경우다. 즉, x2
    */
   
    for (int i = 2; i < N; i++)
        dp[i] = (dp[i - 1] + (dp[i - 2] * 2) % MOD) % MOD;

    cout << dp[N - 1];
    return 0;
}