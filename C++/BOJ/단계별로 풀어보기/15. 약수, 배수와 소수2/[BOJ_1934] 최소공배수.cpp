#include <iostream>
using namespace std;

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int GCD(int x, int y)
{
	int moduler = 0;
	while (x % y != 0)
	{
		moduler = x % y;
		x = y;
		y = moduler;
	}
	return y;
}

int LCM(int x, int y)
{
	return (x * y) / GCD(x, y);
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCM(a, b) << '\n';
	}
	return 0;
}