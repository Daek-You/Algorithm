#include <iostream>
#include <vector>
using namespace std;
const int OPERATOR_COUNT = 4;
int maxValue = -2100000000, minValue = 2100000000;

int Calculate(int num1, int num2, int operatorIdx)
{
	switch (operatorIdx)
	{
	case 0: return num1 + num2;
	case 1: return num1 - num2;
	case 2: return num1 * num2;
	case 3:
		int result = abs(num1) / num2;
		return num1 < 0 ? -result : result;
	}
}

void FindAnswer(const vector<int>& operands, vector<int>& operators, int sum, int idx)
{
	if (idx == operands.size())
	{
		maxValue = max(maxValue, sum);
		minValue = min(minValue, sum);
		return;
	}

	for (int i = 0; i < operators.size(); i++)
	{
		if (operators[i] > 0)
		{
			int result = Calculate(sum, operands[idx], i);
			operators[i]--;
			FindAnswer(operands, operators, result, idx + 1);
			operators[i]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	/* ----------- input -----------*/
	int N;
	cin >> N;

	int firstOperand;
	cin >> firstOperand;

	N -= 1;
	vector<int> operands(N);

	for (int i = 0; i < N; i++)
		cin >> operands[i];

	vector<int> operators(OPERATOR_COUNT);
	for (int i = 0; i < OPERATOR_COUNT; i++)
		cin >> operators[i];
	/* -----------------------------*/

	FindAnswer(operands, operators, firstOperand, 0);
	cout << maxValue << "\n" << minValue;
	return 0;
}
