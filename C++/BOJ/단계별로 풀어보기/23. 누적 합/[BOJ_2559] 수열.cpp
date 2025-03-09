#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	// 1. [0, K - 1]까지 합계 구하기
	int sum = 0;
	vector<int> sequence(N);
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];

		if (i < K)
			sum += sequence[i];
	}

	// 2. start, last 인덱스를 통해, 한 칸씩 전진
	int maxSum = sum;
	for (int start = 0, last = K; last < N; start++, last++)
	{
		sum -= sequence[start];
		sum += sequence[last];

		maxSum = max(maxSum, sum);
	}

	cout << maxSum;
	return 0;
}