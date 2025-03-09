#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int RGB_COUNT = 3;
const int RED_HOUSE = 0;
const int GREEN_HOUSE = 1;
const int BLUE_HOUSE = 2;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	/* --------- 초깃값 세팅 ---------*/
	int N;
	cin >> N;

	vector<int> dp(RGB_COUNT);
	for (int i = 0; i < RGB_COUNT; i++)
		cin >> dp[i];
	/* -------------------------------*/

	// 1번째 집은 세팅했으므로, 2번째 집부터 시작
	for (int i = 1; i < N; i++)
	{
		int redCost, greenCost, blueCost;
		cin >> redCost >> greenCost >> blueCost;

		// i번째 집을 빨강으로 선택할 경우
		redCost += min(dp[GREEN_HOUSE], dp[BLUE_HOUSE]);

		// i번째 집을 초록으로 선택할 경우
		greenCost += min(dp[RED_HOUSE], dp[BLUE_HOUSE]);

		// i번째 집을 초록으로 선택할 경우
		blueCost += min(dp[RED_HOUSE], dp[GREEN_HOUSE]);

		dp[RED_HOUSE] = redCost;
		dp[GREEN_HOUSE] = greenCost;
		dp[BLUE_HOUSE] = blueCost;
	}

	cout << *min_element(dp.begin(), dp.end());
	return 0;
}
