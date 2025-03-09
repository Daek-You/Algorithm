#include <iostream>
using namespace std;

bool IsPrimeNumber(unsigned int num)
{
	if (num == 0 || num == 1)
		return false;

	for (unsigned int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

unsigned int GetNextPrimeNumber(unsigned int num)
{
	while (!IsPrimeNumber(num++));
	return num - 1;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned int testCase;
	cin >> testCase;
	for (unsigned int i = 0; i < testCase; i++)
	{
		unsigned int n;
		cin >> n;
		cout << GetNextPrimeNumber(n) << '\n';
	}
	return 0;
}