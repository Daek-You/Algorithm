#include <iostream>
#include <vector>
using namespace std;
const int DIVISOR = 15746;

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

	/*
		0 : 1	          (1)
		1 : 00, 11		  (2)
		2 : 001, 100, 111 (3)
		3 : 0000, 0011, 1001, 1100, 1111 (5)
		4 : 00001, 00100, 10000, 00111, 10011, 11001, 11100, 11111 (8)
		5 : 000000, 000011, 001001, 100001, 100100, 110000, 001100, 001111, 100111, 110011, 111001, 111100, 111111 (13)
	*/

	vector<long long> dp(N);
	dp[0] = 1, dp[1] = 2;

	for (int i = 2; i < N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % DIVISOR;
	
	cout << dp[N - 1];
	return 0;
}
