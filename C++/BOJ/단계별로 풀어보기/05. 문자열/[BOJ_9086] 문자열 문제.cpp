#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		string word;
		cin >> word;

		cout << *(word.begin()) << *(word.end() - 1) << endl;
	}
	return 0;
}

