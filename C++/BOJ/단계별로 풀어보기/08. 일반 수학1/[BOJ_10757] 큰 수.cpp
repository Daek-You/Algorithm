#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num1, num2;
	cin >> num1 >> num2;

	string answer(max(num1.size(), num2.size()), '0');
	bool carry = false;

	for (int i = 0; i < answer.size(); i++)
	{
		int sum = 0;

		if (i < num1.size())
			sum += num1[num1.size() - i - 1] - '0';
		if (i < num2.size())
			sum += num2[num2.size() - i - 1] - '0';

		sum += carry;

		carry = sum / 10;
		answer[answer.size() - i - 1] = sum % 10 + '0';
	}

	if (carry)
	{
		answer.insert(answer.begin(), carry + '0');
	}

	cout << answer;
	return 0;
}