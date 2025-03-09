#include <iostream>
#include <queue>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> cards;
	for (int i = 1; i <= N; i++)
		cards.push(i);

	while (cards.size() > 1)
	{
		cards.pop();
		int data = cards.front();
		cards.push(data);
		cards.pop();
	}

	cout << cards.front();
	return 0;
}