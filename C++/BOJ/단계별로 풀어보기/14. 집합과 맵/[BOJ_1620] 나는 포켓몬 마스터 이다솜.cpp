#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int pokemonNums, answerNums;
	cin >> pokemonNums >> answerNums;

	map<string, int> maps;
	vector<string> names(pokemonNums);

	for (int i = 0; i < pokemonNums; i++)
	{
		string name;
		cin >> name;
		
		names[i] = name;
		maps.insert(make_pair(name, i + 1));
	}

	for (int i = 0; i < answerNums; i++)
	{
		string quesition;
		cin >> quesition;

		if (isdigit(quesition[0]))
			cout << names[stoi(quesition) - 1] << '\n';
		else
		{
			auto findIt = maps.find(quesition);
			if (findIt != maps.end())
				cout << findIt->second << '\n';
		}
	}

	return 0;
}
