#include <iostream>
#include <vector>
using namespace std;
using Apartment = vector<vector<int>>;
using Floor = vector<int>;
const int MAX_ROOM_COUNT = 15;


void SetFastIO()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}

void Accumulate(Apartment& dp, int k)
{
	for (int i = 1; i < MAX_ROOM_COUNT; i++)
		dp[k][i] = dp[k][i - 1] + dp[k-1][i];  // k층 i호실 인원 수 = k층 i-1호실까지의 누적합 + k-1층의 i호실
}

int main()
{
	SetFastIO();

	int T, k, n;
	cin >> T;

	Apartment dp(MAX_ROOM_COUNT, Floor(MAX_ROOM_COUNT));
	dp[0] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	for (int i = 1; i < MAX_ROOM_COUNT; i++)
		Accumulate(dp, i);

	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}

	return 0;
}
