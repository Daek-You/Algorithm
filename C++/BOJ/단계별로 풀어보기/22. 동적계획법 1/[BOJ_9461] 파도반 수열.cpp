#include <iostream>
#include <vector>
using namespace std;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

long long PadovanSequence(int N)
{
	if (N == 1 or N == 2 or N == 3)
		return 1;

	// index 계산하기 쉽게, 1번부터 시작
	vector<long long> dp(N + 1);
	dp[1] = 1, dp[2] = 1, dp[3] = 1;

	for (int i = 4; i <= N; i++)
		dp[i] = dp[i - 3] + dp[i - 2];  // 파도반 수열의 규칙
	return dp[N];
}

int main()
{
	SetFastIO();
	int testCaseCount;
	cin >> testCaseCount;

	for (int i = 0; i < testCaseCount; i++)
	{
		int N;
		cin >> N;
		cout << PadovanSequence(N) << "\n";
	}
	return 0;
}
