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

unsigned int GetPrimeNumberCount(unsigned int num)
{
	unsigned int answer = 0;
	for (unsigned int i = num + 1; i <= num * 2; i++)
	{
		if (IsPrimeNumber(i))
			answer++;
	}
	return answer;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		unsigned int n;
		cin >> n;

		if (n == 0)
			break;
		cout << GetPrimeNumberCount(n) << '\n';
	}
	return 0;
}