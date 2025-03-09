#include <iostream>
#include <vector>
using namespace std;
int recursionCall = 0;
int dpCall = 0;

int Fib(int n)
{

	if (n == 1 or n == 2)
	{
		recursionCall++;
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}


int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> dp(N + 1);
	dp[0] = 1, dp[1] = 1;

	// 재귀
	Fib(N);

	// dp
	for (int i = 3; i <= N; i++)
	{
		dpCall++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << recursionCall << " " << dpCall;
	return 0;
}
