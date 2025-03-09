#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string& word1, const string& word2)
{
	if (word1.length() == word2.length())
		return word1.compare(word2) < 0;
	return word1.length() < word2.length();
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	set<string> words;
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		words.insert(word);
	}

	vector<string> distinctwords;
	for (const auto word : words)
		distinctwords.push_back(word);


	sort(distinctwords.begin(), distinctwords.end(), compare);
	for (const auto word : distinctwords)
		cout << word << '\n';
	return 0;
}