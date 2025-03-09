#include <iostream>
using namespace std;

bool IsPrimeNumber(int number)
{
	if (number == 1)
		return false;

	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
			return false;
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, number, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number;

		if (IsPrimeNumber(number))
			count++;
	}

	cout << count;
	return 0;
}