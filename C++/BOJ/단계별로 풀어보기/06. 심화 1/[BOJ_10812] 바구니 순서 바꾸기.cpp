#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int>& baskets)
{
	for (auto element : baskets)
		cout << element << " ";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> baskets;
	for (int i = 0; i < N; i++)
		baskets.push_back(i + 1);


	for (int i = 0; i < M; i++)
	{
		int begin, end, mid;
		cin >> begin >> end >> mid;

		rotate(baskets.begin() + begin - 1, baskets.begin() + mid - 1, baskets.begin() + end);
		// rotate(시작, 중간, 끝);  -> 시작(포함), 중간(포함), 끝(포함 X)
	}

	Print(baskets);
	return 0;
}