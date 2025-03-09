#include <iostream>
#include <vector>
#include <algorithm>
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

	vector<int> wineAmounts(N);
	for (int i = 0; i < N; i++)
		cin >> wineAmounts[i];

	if (N == 1)
		cout << wineAmounts[0];
	else if (N == 2)
		cout << wineAmounts[0] + wineAmounts[1];
	else
	{
		vector<int> dp(N);
		dp[0] = wineAmounts[0];
		dp[1] = wineAmounts[0] + wineAmounts[1];
		dp[2] = max({(wineAmounts[0] + wineAmounts[1]), (wineAmounts[1] + wineAmounts[2]), (wineAmounts[0] + wineAmounts[2])});

		for (int i = 3; i < N; i++)
			dp[i] = max({dp[i-1], dp[i - 2] + wineAmounts[i], dp[i - 3] + wineAmounts[i - 1] + wineAmounts[i] });
		cout << dp[N - 1];
	}

	return 0;
}
