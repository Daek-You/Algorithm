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

void Combination(vector<int>& answers, int N, int M, int currentNum)
{
	if (answers.size() == M)
	{
		Print(answers);
		return;
	}

	for (int i = currentNum + 1; i <= N; i++)
	{
		answers.push_back(i);
		Combination(answers, N, M, currentNum);
		answers.pop_back();
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

	Combination(answers, N, M, 0);
	return 0;
}
