#include <iostream>
using namespace std;

int main(void){
	int a, b;
	cin >> a >> b;

	cout.precision(12);
	cout << (double)a / b;
}