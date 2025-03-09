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

	vector<int> dp(N);
	dp[0] = 1;
	
	if (N >= 2)
		dp[1] = 2;

	for (int i = 2; i < N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	cout << dp[N - 1];
	
	return 0;
}
