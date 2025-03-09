#include <iostream>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

bool IsExplosionString(const string& explosionString, const string& targetString)
{
	if (targetString.size() < explosionString.size())
		return false;

	int targetIdx = targetString.size() - 1;
	for (int expIdx = explosionString.size() - 1; expIdx >= 0;)
	{
		if (targetString[targetIdx--] != explosionString[expIdx--])
			return false;
	}

	return true;
}

int main()
{
	FAST_IO
	string str, explosionString;
	cin >> str >> explosionString;

	string answer;
	for (const auto& character : str)
	{
		answer.push_back(character);

		if (character == explosionString.back())
		{
			if (!IsExplosionString(explosionString, answer))
				continue;

			for (int i = 0; i < explosionString.size(); i++)
				answer.pop_back();
		}
	}

	if (answer.empty())
		cout << "FRULA";
	else
		cout << answer;
	return 0;
}
