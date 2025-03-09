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
	cin >> dp[0];
	int maxElement = dp[0];

	for (int i = 1; i < N; i++)
	{
		int data;
		cin >> data;

		// (이전 최댓값 + 현재값) vs (현재값) 중에 큰 걸 선택
		dp[i] = max(dp[i - 1] + data, data);
		maxElement = dp[i] > maxElement ? dp[i] : maxElement;
	}

	cout << maxElement;
	return 0;
}