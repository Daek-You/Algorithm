#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int alphabet[26];
	string input;

	cin >> input;

	for (int i = 0; i < 26; i++) {
		int idx = input.find((char)(97+i));
			alphabet[i] = idx;
	}

	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";
}