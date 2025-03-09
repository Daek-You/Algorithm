#include <iostream>
#include <vector>
using namespace std;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

int main()
{
	SetFastIO();
	int N;
	cin >> N;

	vector<int> stairsCosts(N);
	vector<int> dp(N);

	for (int i = 0; i < N; i++)
		cin >> stairsCosts[i];

	dp[0] = stairsCosts[0];
	dp[1] = max(stairsCosts[0] + stairsCosts[1], stairsCosts[1]);
	dp[2] = max(stairsCosts[0] + stairsCosts[2], stairsCosts[1] + stairsCosts[2]);

	for (int i = 3; i < N; i++)
		dp[i] = max(dp[i - 2] + stairsCosts[i], dp[i - 3] + stairsCosts[i - 1] + stairsCosts[i]);

	cout << dp[N - 1];
	return 0;
}
