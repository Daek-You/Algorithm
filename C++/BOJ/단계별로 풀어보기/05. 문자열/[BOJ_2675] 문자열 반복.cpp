#include <iostream>
#include <string>
using namespace std;

int main() {

	int trying, repeat;
	string txt;
	string* arr;

	cin >> trying;
	arr = new string[trying];

	for (int i = 0; i < trying; i++) {
		cin >> repeat >> txt;
		int N = txt.length();

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < repeat; k++) {
				arr[i].push_back(txt[j]);
			}
		}
	}

	for (int i = 0; i < trying; i++)
		cout << arr[i] << endl;
	delete[]arr;
}