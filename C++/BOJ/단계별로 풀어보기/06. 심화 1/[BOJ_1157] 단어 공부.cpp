#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;

	int alphabets[26] = { 0 };
	const int lower_A_ASICC = 97;

	for (const auto alphabet : word)
	{
		int index = tolower(alphabet) - lower_A_ASICC;
		alphabets[index]++;
	}


	int maxValue = alphabets[0];
	int index = 0;
	bool isDuplicated = false;

	for (int i = 1; i < 26; i++)
	{
		if (maxValue < alphabets[i])
		{
			maxValue = alphabets[i];
			index = i;
			isDuplicated = false;
		}

		else if (maxValue == alphabets[i])
		{
			isDuplicated = true;
		}
	}

	if (isDuplicated)
		cout << "?";
	else
		cout << static_cast<char>(toupper((index + lower_A_ASICC)));

	return 0;
}