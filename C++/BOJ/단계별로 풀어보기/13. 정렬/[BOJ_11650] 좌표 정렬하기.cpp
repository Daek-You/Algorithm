#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> position1, pair<int, int> position2)
{
	if (position1.first == position2.first)
		return position1.second < position2.second;
	return position1.first < position2.first;
}


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> positions(N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		positions[i] = make_pair(x, y);
	}

	sort(positions.begin(), positions.end(), compare);

	for (const auto result : positions)
		cout << result.first << ' ' << result.second << '\n';
	return 0;
}
