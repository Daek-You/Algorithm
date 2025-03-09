#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string num1, num2;
	cin >> num1 >> num2;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int sangsuNum1 = stoi(num1), sangsuNum2 = stoi(num2);
	int answer = (sangsuNum1 > sangsuNum2) ? sangsuNum1 : sangsuNum2;
	
	cout << answer;
	return 0;
}

