#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int i = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = N - i - 1; j > 0; j--)
		{
			cout << " ";
		}

		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}

		for (int m = 0; m < i; m++)
		{
			cout << "*";
		}
		cout << endl;
	}


	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int k = N - i; k > 0; k--)
		{
			cout << "*";
		}

		for (int m = N - i - 1; m > 0; m--)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}