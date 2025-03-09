#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);

	map<string, int> words;
	istringstream iss(sentence);

	string buffer;
	
	while (getline(iss, buffer, ' '))
	{
		if (buffer.empty())
			continue;

		auto it = words.find(buffer);
		if (it == words.end())
		{
			words.insert(make_pair(buffer, 1));
		}
		else
		{
			words[buffer] += 1;
		}
	}

	int totalWords = 0;
	for (auto value : words)
	{
		totalWords += value.second;
	}

	cout << totalWords;

	return 0;
}

