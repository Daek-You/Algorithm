#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;

	int wordLength = word.size();
	bool isPalindrome = true;

	for (int i = 0; i < wordLength / 2; i++)
	{
		if (word[i] != word[wordLength - i - 1])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << isPalindrome;
	return 0;
}