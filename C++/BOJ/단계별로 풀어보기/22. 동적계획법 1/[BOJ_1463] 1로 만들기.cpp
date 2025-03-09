#include <iostream>
#include <vector>
using namespace std;
const int INIT_VALUE = 100000000;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

void FindAnswer(int N, vector<int>& dp, int operationCount)
{
	if (N == 1)
	{
		dp[N] = min(dp[N], operationCount);
		return;
	}

	if (dp[N] < operationCount)
		return;

	dp[N] = operationCount;

	if (N % 3 == 0)
		FindAnswer(N / 3, dp, operationCount + 1);
	if (N % 2 == 0)
		FindAnswer(N / 2, dp, operationCount + 1);
	FindAnswer(N - 1, dp, operationCount + 1);
}

int main()
{
	SetFastIO();
	int N;
	cin >> N;

	vector<int> dp(N + 1, INIT_VALUE);
	FindAnswer(N, dp, 0);

	cout << dp[1];
	return 0;
}
