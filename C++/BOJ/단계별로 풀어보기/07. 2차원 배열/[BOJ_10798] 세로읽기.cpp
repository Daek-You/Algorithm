#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int INPUT_NUM = 5;
	vector<string> words;
	int maxWordLength = 0;

	// --------- 입력 받기--------------------
	for (int i = 0; i < INPUT_NUM; i++)
	{
		string word;
		cin >> word;

		if (maxWordLength < word.length())
			maxWordLength = word.length();
		words.push_back(word);
	}
	// --------------------------------------

	string answer;

	for (int charIdx = 0; charIdx < maxWordLength; charIdx++)
	{
		for (int wordIdx = 0; wordIdx < INPUT_NUM; wordIdx++)
		{
			string word = words[wordIdx];

			if (charIdx >= word.length())     // 단어의 길이가 짧아, 읽을 게 없다는 의미이므로
				continue;

			answer.push_back(word[charIdx]);
		}
	}

	cout << answer;
	return 0;
}