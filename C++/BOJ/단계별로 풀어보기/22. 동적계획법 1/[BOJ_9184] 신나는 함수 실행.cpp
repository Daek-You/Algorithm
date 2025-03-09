#include <iostream>
const int MAX_SIZE = 21;
using namespace std;
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0, };

int w(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;

	if (a > 20 or b > 20 or c > 20)
		return w(20, 20, 20);

	if (dp[a][b][c] != 0)
		return dp[a][b][c];

	if (a < b and b < c)
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;

		if (a == -1 and b == -1 and c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}

	return 0;
}
