#include <iostream>
using namespace std;

unsigned long long Factorial(int N)
{
	if (N == 0)
		return 1;
	return N * Factorial(N - 1);
}

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	cout << Factorial(N);
	return 0;
}