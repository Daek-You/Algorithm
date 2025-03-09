#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int index;

	cin >> word;
	cin >> index;

	for (int i = 0; i < word.size(); i++)
	{
		if (index - 1 == i)
		{
			cout << word[i];
			break;
		}
	}

	return 0;
}

