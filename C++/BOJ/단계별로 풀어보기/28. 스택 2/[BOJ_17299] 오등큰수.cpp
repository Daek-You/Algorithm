#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
	FAST_IO
	int N;
	cin >> N;

	vector<int> sequences(N);
	unordered_map<int, int> counts;
	for (int i = 0; i < N; i++)
	{
		cin >> sequences[i];
		counts[sequences[i]]++;
	}

	vector<int> answers(N, -1);
	stack<pair<int, int>> stacks;   // <Ai, F(Ai)>
	stacks.emplace(sequences[N - 1], counts[sequences[N - 1]]);

	for (int i = N - 2; i >= 0; i--)
	{
		int ai = sequences[i];
		int currentCount = counts[ai];

		// F(ai) >= F(stacks.top())이라면, stack.top()은 오큰등수가 될 수 없다.
		while (!stacks.empty() and currentCount >= stacks.top().second)
			stacks.pop();

		if (!stacks.empty() and currentCount < stacks.top().second)
			answers[i] = stacks.top().first;
		stacks.emplace(ai, currentCount);
	}

	for (const auto& answer : answers)
		cout << answer << " ";
	return 0;
}
