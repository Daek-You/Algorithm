#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1 2 5 10 20 25 50 100
	- 주어진 약수 리스트들 중, 중앙값의 제곱이 바로 찾는 수가 된다.
*/

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> divisors(N);
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		divisors[i] = data;
	}

	sort(divisors.begin(), divisors.end());

	if (N % 2 != 0)
		cout << divisors[N / 2] * divisors[N / 2];
	else
		cout << divisors[(N / 2) - 1] * divisors[N / 2];
	return 0;
}