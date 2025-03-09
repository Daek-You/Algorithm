#include <iostream>
#include <vector>
using namespace std;
const int DIVISOR = 9901;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N;
	cin >> N;

	/*
	   맨 위의 첫 줄은 다음과 같은 3가지 상황만이 존재
	   - [][], [o][], [][o]

	   이것을 기준으로 n번 행까지 확장하여 경우의 수를 세면, 다음과 같은 규칙이 생성됨
		n = 1: [][], [o][], [][o] : 3
				1      1      1

		n = 2: [][], [o][], [][o] : 7
				3      2     2

		n = 3: [][], [o][], [][o] : 17
				7      5      5

		n = 4: [][], [o][], [][o] : 41
				17     12     12
		...
	*/ 

	int nothing = 1, existOne = 1;
	for (int i = 1; i < N; i++)
	{
		int temp = existOne;
		existOne = (existOne + nothing) % DIVISOR;
		nothing = (nothing + temp * 2) % DIVISOR;
	}

	cout << (nothing + existOne * 2) % DIVISOR;
	return 0;
}