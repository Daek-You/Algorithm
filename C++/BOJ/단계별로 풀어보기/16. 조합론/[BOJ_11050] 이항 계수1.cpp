#include <iostream>
using namespace std;

unsigned int Factorial(unsigned int n)
{
	if (n == 0)
		return 1;
	return n * Factorial(n - 1);
}

unsigned int Combination(unsigned int n, unsigned int k)
{
	return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	cout << Combination(n, k);
	return 0;
}