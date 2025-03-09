#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	map<int, int> cardCounts;
	for (int i = 0; i < N; i++)
	{
		int cardNum;
		cin >> cardNum;

		auto findIt = cardCounts.find(cardNum);
		if (findIt != cardCounts.end())
			findIt->second++;
		else
			cardCounts.insert(make_pair(cardNum, 1));
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int findCardNum;
		cin >> findCardNum;

		auto findIt = cardCounts.find(findCardNum);
		if (findIt != cardCounts.end())
			cout << findIt->second << ' ';
		else
			cout << 0 << ' ';
	}

	return 0;
}
