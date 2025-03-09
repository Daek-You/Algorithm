#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int X;
	cin >> X;

	int index = 1;
	int addNum = 1;

	while (index + addNum <= X)
	{
		index += addNum;
		addNum++;
	}

	int difference = X - index;
	difference = difference > 0 ? difference : -difference;

	int denominator = addNum;        // 분모
	int numerator = 1;               // 분자

	// 분자 + 분모 = 홀수(오른쪽 위 -> 왼쪽 아래)
	if ((denominator + numerator) % 2 != 0)
	{
		denominator = addNum;
		numerator = 1;
		denominator -= difference;
		numerator += difference;
	}

	// 분자 + 분모 = 짝수(왼쪽 아래 -> 오른쪽 위)
	else
	{
		denominator = 1;
		numerator = addNum;
		denominator += difference;
		numerator -= difference;
	}

	cout << numerator << "/" << denominator;

	return 0;
}