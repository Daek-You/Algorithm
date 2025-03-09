#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool Compare(const pair<string, int> word1, const pair<string, int> word2)
{
	if (word1.second != word2.second)
		return word1.second > word2.second;
	if (word1.first.length() != word2.first.length())
		return word1.first.length() > word2.first.length();
	return word1.first.compare(word2.first) < 0;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	unordered_map<string, int> wordList;
	int wordNums, standardLength;
	cin >> wordNums >> standardLength;

	for (int i = 0; i < wordNums; i++)
	{
		string word;
		cin >> word;

		if (word.length() < standardLength)
			continue;

		auto findIt = wordList.find(word);
		if (findIt != wordList.end())
			findIt->second++;
		else
			wordList.insert(make_pair(word, 1));
	}

	vector<pair<string, int>> words(wordList.begin(), wordList.end());
	sort(words.begin(), words.end(), Compare);

	for (const auto word : words)
		cout << word.first << '\n';
	return 0;
}