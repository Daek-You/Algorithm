#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<unsigned int> accountBook;
	int K;
	cin >> K;

	unsigned int sum = 0;
	for (int i = 0; i < K; i++)
	{
		unsigned int data;
		cin >> data;

		if (data == 0 && !accountBook.empty())
		{
			unsigned int eraseData = accountBook.top();
			sum -= eraseData;
			accountBook.pop();
			continue;
		}

		accountBook.push(data);
		sum += data;
	}

	cout << sum;
	return 0;
}