#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int N = sticker.size();
    
    if (N == 1) return sticker[0];
    vector<int> dp(N);

    // 첫 번째 스티커를 뜯는 경우
    dp[0] = dp[1] = sticker[0];
    for(int i = 2; i < N - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    answer = dp[N - 2];
    
    // 첫 번째 스티커를 뜯지 않는 경우
    dp[0] = 0, dp[1] = sticker[1];
    for(int i = 2; i < N; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    answer = max(answer, dp[N - 1]);
    
    return answer;
}