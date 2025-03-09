#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	// 최솟값(n0)을 넣었을 때 만족하는지와, 두 직선의 기울기를 비교하여 풀 수 있다.
	if ((a1 * n0 + a0) <= c * n0 && a1 <= c)
		cout << true;
	else
		cout << false;

	return 0;
}