#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string word;
	cin >> word;

	set<string> croatiaAlphabets
	{
		"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
	};

	for (auto alphabet = croatiaAlphabets.begin(); alphabet != croatiaAlphabets.end(); alphabet++)
	{
		while (true)
		{
			size_t position = word.find(*alphabet);

			if (position == word.npos)
				break;

			size_t end = alphabet->size();
			word.replace(position, end, "*");
		}
	}

	cout << word.length();
	return 0;
}