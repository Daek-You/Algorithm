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

int SumPrimeNumbersAndReferenceMinPrimeNum(int start, int last, int& minPrimeNum)
{
	int sum = 0;
	bool isFirstPrimeNum = true;

	for (int i = start; i <= last; i++)
	{
		if (IsPrimeNumber(i))
		{
			sum += i;

			if (isFirstPrimeNum)
			{
				isFirstPrimeNum = false;
				minPrimeNum = i;
			}
		}
	}

	if (sum == 0)
		return -1;
	return sum;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	int minPrimeNum = 0;
	int answer = SumPrimeNumbersAndReferenceMinPrimeNum(M, N, minPrimeNum);

	if (answer == -1)
	{
		cout << "-1";
	}
	else
	{
		cout << answer << endl;
		cout << minPrimeNum;
	}

	return 0;
}