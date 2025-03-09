#include <iostream>
#include <vector>
using namespace std;
const int MAX_INPUT_SIZE = 10;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

int main()
{
	SetFastIO();

	int T, n;
	cin >> T;

	vector<int> dp(MAX_INPUT_SIZE + 1);
	dp[1] = 1, dp[2] = 2, dp[3] = 4;

	for (int i = 4; i <= MAX_INPUT_SIZE; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i-1];

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
