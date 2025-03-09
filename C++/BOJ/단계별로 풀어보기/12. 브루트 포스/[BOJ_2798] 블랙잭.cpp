#include <iostream>
#include <vector>
using namespace std;

int Sum(const vector<int>& cards)
{
	int sum = 0;
	for (const auto card : cards)
		sum += card;
	return sum;
}

void Search(const vector<int>& cards, vector<int>& selectedCards, int lastIdx, int& maxSum, const int M)
{
	if (selectedCards.size() == 3)
	{
		int currentSum = Sum(selectedCards);
		if (currentSum > maxSum && currentSum <= M)
			maxSum = currentSum;
		return;
	}

	lastIdx = (selectedCards.size() == 0) ? -1 : lastIdx;

	for (int i = lastIdx + 1; i < cards.size(); i++)
	{
		selectedCards.push_back(cards[i]);
		Search(cards, selectedCards, i, maxSum, M);
		selectedCards.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> cards(N, 0);
	for (int i = 0; i < cards.size(); i++)
	{
		int cardNum;
		cin >> cardNum;
		cards[i] = cardNum;
	}

	vector<int> selectionCards;
	int answer = 0;
	Search(cards, selectionCards, 0, answer, M);

	cout << answer;
	return 0;
}