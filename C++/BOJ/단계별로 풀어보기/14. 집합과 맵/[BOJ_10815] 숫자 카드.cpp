#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	set<int> myCards;
	for (int i = 0; i < N; i++)
	{
		int cardNum;
		cin >> cardNum;
		myCards.insert(cardNum);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int cardNum;
		cin >> cardNum;

		auto findIterator = myCards.find(cardNum);
		if (findIterator != myCards.end())
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}
