#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int FindMaxDistance(const vector<int>& positions, const int N, const int C)
{
	int left = 0, right = positions.back() - positions.front();
	int distance = 1;

	while (left <= right)
	{
		int routerCount = 1;
		int range = (right + left) / 2;
		int currentPosition = positions.front();

		for (int i = 1; i < N; i++)
		{
			if (positions[i] - currentPosition >= range)
			{
				routerCount++;
				currentPosition = positions[i];
			}
		}
			
		if (routerCount < C)
			right = range - 1;
		else
		{
			left = range + 1;
			distance = range;
		}
	}

	return distance;
}

int main()
{
	FAST_IO
	int N, C;
	cin >> N >> C;

	vector<int> positions(N);
	for (int i = 0; i < N; i++)
		cin >> positions[i];

	sort(positions.begin(), positions.end());
	cout << FindMaxDistance(positions, N, C);
	return 0;
}
