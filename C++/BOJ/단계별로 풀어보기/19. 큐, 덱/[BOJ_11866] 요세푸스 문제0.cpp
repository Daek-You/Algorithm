#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	deque<int> circle;
	for (int i = 1; i <= N; i++)
		circle.push_back(i);

	int removeTarget = 0;
	vector<int> answer;

	while (!circle.empty())
	{
		removeTarget = (removeTarget + K - 1) % circle.size();
		answer.push_back(circle[removeTarget]);
		circle.erase(circle.begin() + (removeTarget));
	}

	cout << '<';
	for (int i = 0; i < N; i++)
	{
		cout << answer[i];

		if (i != N - 1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}