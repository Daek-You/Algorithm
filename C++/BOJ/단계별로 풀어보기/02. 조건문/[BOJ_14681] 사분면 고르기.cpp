#include <iostream>
#include <string>
using namespace std;

int main() {
	int posX, posY;
	cin >> posX >> posY;

	if (posX > 0 && posY > 0)
		cout << '1';
	else if (posX < 0 && posY > 0)
		cout << '2';
	else if (posX < 0 && posY < 0)
		cout << '3';
	else if (posX > 0 && posY < 0)
		cout << '4';
}