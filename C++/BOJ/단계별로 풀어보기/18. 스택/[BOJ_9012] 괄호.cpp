#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		string data;
		cin >> data;

		stack<char> parenthesises;
		bool isUnvalidCase = false;
		for (const auto parenthesis : data)
		{
			if (parenthesis == '(')
				parenthesises.push(parenthesis);

			else if (parenthesises.empty() and parenthesis == ')')
			{
				isUnvalidCase = true;
				break;
			}

			else if (parenthesis == ')')
				parenthesises.pop();
		}

		if (!parenthesises.empty() || isUnvalidCase)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}