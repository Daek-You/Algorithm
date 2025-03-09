#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* GetDivisors(int number)
{
	vector<int>* divisors = new vector<int>();

	for (int i = 1; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			divisors->push_back(i);

			if (number / i != i)
				divisors->push_back(number / i);
		}
	}

	sort(divisors->begin(), divisors->end());
	return divisors;
}

bool isPerfectNumber(vector<int>& divisors)
{
	int sum = 0;

	for (int i = 0; i < divisors.size() - 1; i++)
		sum += divisors[i];

	return sum == divisors[divisors.size() - 1];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	while (true)
	{
		cin >> num;

		if (num == -1)
			break;

		vector<int>* divisors = GetDivisors(num);

		if (isPerfectNumber(*divisors))
		{
			cout << num << " = ";
			int N = divisors->size() - 1;

			for (int i = 0; i < N; i++)
			{
				cout << (*divisors)[i];            // 배열참조 연산자가 우선 순위가 더 높으므로 괄호 쳐주기

				if (i < N - 1)
					cout << " + ";
			}

			cout << endl;
		}
		else
			cout << num << " is NOT perfect." << endl;

		delete divisors;
	}

	return 0;
}