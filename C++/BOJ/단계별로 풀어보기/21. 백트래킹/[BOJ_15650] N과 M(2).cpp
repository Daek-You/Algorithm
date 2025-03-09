#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& answers)
{
	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i];
		if (i != answers.size())
			cout << " ";
	}
	cout << '\n';
}

void Combination(vector<int>& answers, vector<bool>& containsNum, int N, int M, int currentNum, int previousNum)
{
	if (answers.size() == M)
	{
		Print(answers);
		return;
	}

	for (int i = currentNum + 1; i <= N; i++)
	{
		if (containsNum[i])
			continue;

		if (previousNum > i)
			continue;

		answers.push_back(i);
		containsNum[i] = true;
		previousNum = i;

		Combination(answers, containsNum, N, M, currentNum, previousNum);

		answers.pop_back();
		containsNum[i] = false;
		previousNum = answers.empty() ? -1 : answers[answers.size() - 1];
	}
}

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> answers;
	int N, M;
	cin >> N >> M;

	vector<bool> containsNum(N + 1, false);
	Combination(answers, containsNum, N, M, 0, -1);
	return 0;
}