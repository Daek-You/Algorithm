#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int Palindrome(const vector<int>& sequence, vector<vector<int>>& dp, int start, int end)
{
    if (start >= end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];
    
    dp[start][end] = 0;
    
    if (sequence[start] == sequence[end])
        return dp[start][end] += Palindrome(sequence, dp, start + 1, end - 1);
    return dp[start][end] += 1 + min(Palindrome(sequence, dp, start + 1, end), Palindrome(sequence, dp, start, end - 1));
}

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> sequence(N);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int answer = Palindrome(sequence, dp, 0, N - 1);

    cout << answer;
    return 0;
}