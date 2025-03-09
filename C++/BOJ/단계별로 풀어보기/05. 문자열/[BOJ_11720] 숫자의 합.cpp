#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int trying, sum = 0;
	string numericTxt;
	cin >> trying;
	cin >> numericTxt;

	for (int i = 0; i < trying; i++) {
		int num = numericTxt[i] - '0';
		sum += num;
	}
	cout << sum;
}