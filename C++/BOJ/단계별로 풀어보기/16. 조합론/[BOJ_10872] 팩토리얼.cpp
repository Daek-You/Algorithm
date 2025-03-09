#include <iostream>
using namespace std;

unsigned int Factorial(unsigned int n)
{
	if (n == 0)
		return 1;
	return n * Factorial(n - 1);
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	cout << Factorial(N);
	return 0;
}