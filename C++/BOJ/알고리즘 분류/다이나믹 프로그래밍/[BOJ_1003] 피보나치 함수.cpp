#include <iostream>
#include <vector>
using namespace std;
using Count = pair<int, int>;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

int main()
{
	SetFastIO();

	const int MAX_INPUT_SIZE = 41;
	vector<Count> dp(MAX_INPUT_SIZE);
	dp[0] = Count(1, 0), dp[1] = Count(0, 1);

	for (int i = 2; i < MAX_INPUT_SIZE; i++)
	{
		int sumOfZeroCount = dp[i - 1].first + dp[i - 2].first;
		int sumOfOneCount = dp[i - 1].second + dp[i - 2].second;
		dp[i] = Count(sumOfZeroCount, sumOfOneCount);
	}

	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int N;
		cin >> N;
		cout << dp[N].first << " " << dp[N].second << "\n";
	}

	return 0;
}
