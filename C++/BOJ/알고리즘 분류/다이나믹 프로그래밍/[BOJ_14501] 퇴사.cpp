#include <iostream>
#include <vector>
using namespace std;
const int MAX_PERIOD = 5;

void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

struct Counsel
{
	Counsel() { }
	Counsel(int period, int cost) : _period(period), _cost(cost) { }
	int _period;
	int _cost;
};

int main()
{
	SetFastIO();

	int N, period, cost;
	cin >> N;
	int maxRange = N + 1 + MAX_PERIOD;
	
	vector<Counsel> counsels(maxRange);
	for (int i = 1; i <= N; i++)
	{
		cin >> period >> cost;
		counsels[i] = Counsel(period, cost);
	}

	vector<int> dp(maxRange);
	const Counsel& lastestCounsel = counsels[N];
	dp[N] = (N + lastestCounsel._period <= N + 1) ? lastestCounsel._cost : 0;

	for (int i = N - 1; i > 0; i--)
	{
		int next = i + counsels[i]._period;
		if (next > N + 1)
		{
			dp[i] = dp[i + 1];
			continue;
		}

		dp[i] = max(dp[i + 1], counsels[i]._cost + dp[next]);
	}

	cout << dp[1];
	return 0;
}
