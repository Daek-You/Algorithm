#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX_COLUMN 3


int main()
{
	FAST_IO
	int N;
	cin >> N;

	vector<int> maxDP(MAX_COLUMN), minDP(MAX_COLUMN), input(MAX_COLUMN);
	for (int i = 0; i < MAX_COLUMN; i++)	cin >> input[i];
	for (int i = 0; i < MAX_COLUMN; i++)	maxDP[i] = minDP[i] = input[i];

	for (int row = 1; row < N; row++)
	{
		for (int i = 0; i < MAX_COLUMN; i++)	cin >> input[i];
		vector<int> originMaxDP = maxDP, originMinDP = minDP;
		
		maxDP[0] = max(originMaxDP[0], originMaxDP[1]) + input[0];
		maxDP[1] = max({originMaxDP[0], originMaxDP[1], originMaxDP[2]}) + input[1];
		maxDP[2] = max({originMaxDP[1], originMaxDP[2]}) + input[2];

		minDP[0] = min(originMinDP[0], originMinDP[1]) + input[0];
		minDP[1] = min({originMinDP[0], originMinDP[1], originMinDP[2]}) + input[1];
		minDP[2] = min(originMinDP[1], originMinDP[2]) + input[2];
	}

	int maxValue = *max_element(maxDP.begin(), maxDP.end());
	int minValue = *min_element(minDP.begin(), minDP.end());

	cout << maxValue << " " << minValue;
	return 0;
}