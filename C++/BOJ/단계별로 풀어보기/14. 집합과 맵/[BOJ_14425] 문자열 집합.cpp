#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	set<string> words;
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		words.insert(word);
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		string compareWord;
		cin >> compareWord;

		auto findIt = words.find(compareWord);
		if (findIt != words.end())
			answer++;
	}

	cout << answer;
	return 0;
}
