#include <iostream>
#include <vector>
using namespace std;


bool IsConstructor(int num, int N)
{
	int originalNum = num;

	while (num != 0)
	{
		originalNum += num % 10;
		num /= 10;
	}
	
	return originalNum == N;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int answer = 0;
	const int max_range = 9 * 6;

	/*
		N의 최대 크기가 1,000,000이다.
		각 자릿수의 합이 최대가 되려면 999,999이어야 하므로 9 * 6 = 54이다.
		즉, 54를 넘는 범위까지는 탐색할 필요가 없다.
	*/
	int target = N - max_range <= 0 ? 1 : N - max_range;

	for (; target < N; target++)
	{
		if (IsConstructor(target, N))
		{
			answer = target;
			break;
		}
	}

	cout << answer;
	return 0;
}