#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define FAST_IO cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using uint32 = unsigned int;

int main()
{
	FAST_IO

	int N;
	cin >> N;

	vector<uint32> budgets(N);
	for (int i = 0; i < N; i++)
		cin >> budgets[i];

	sort(budgets.begin(), budgets.end());
	uint32 start = 1, last = budgets.back();
	
	uint32 M;
	cin >> M;

	if (accumulate(budgets.begin(), budgets.end(), 0) <= M)
	{
		cout << budgets.back();
		return 0;
	}


	uint32 answer = 0;
	while (start <= last)
	{
		uint32 mid = (start + last) / 2;
		uint32 money = 0;

		for (const auto& budget : budgets)
			money += (budget <= mid) ? budget : mid;

		if (money <= M)
		{
			start = mid + 1;
			answer = max(answer, mid);
		}
		else
			last = mid - 1;
	}

	cout << answer;
	return 0;
}