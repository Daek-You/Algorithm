#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> sequence(n);
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		sequence[i] = number;
	}


	int number = 1;
	stack<int> sequenceStack;
	vector<char> answers;
	bool isValidCase = true;

	for (int i = 0; i < n; i++)
	{
		if (number <= sequence[i])
		{
			while (number <= sequence[i])
			{
				sequenceStack.push(number);
				number++;
				answers.push_back('+');
			}

			sequenceStack.pop();
			answers.push_back('-');
			continue;
		}

		// 스택의 제일 뒷 숫자보다 수열의 숫자가 작다면, 만들 수 없는 경우의 수
		if (sequence[i] < sequenceStack.top())
		{
			isValidCase = false;
			break;
		}

		sequenceStack.pop();
		answers.push_back('-');
	}
	
	if (!isValidCase)
		cout << "NO";
	else
	{
		for (const auto result : answers)
			cout << result << '\n';
	}
	return 0;
}