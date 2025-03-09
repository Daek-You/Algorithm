#include <iostream>
#define FAST_IO cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using uint32 = unsigned int;


// midValue보다 작은 숫자 개수 찾기
uint32 CountNumbersUntil(const uint32 untilNum, const uint32 N)
{
	uint32 count = 0;
	for (uint32 i = 1; i <= N; i++)
		count += min((untilNum / i), N);
	return count;
}

int main()
{
	FAST_IO

	int N, k;
	cin >> N >> k;

	uint32 minValue = 1, maxValue = N * N;
	uint32 answer = maxValue;

	// "B[k] = midValue" 에서 midValue보다 작거나 같은 숫자가 k개 이상일 때의 midValue를 찾아라. (with Binary Search)
	while (minValue <= maxValue)
	{
		uint32 midValue = (minValue + maxValue) / 2;
		uint32 countNumsUntilMidValue = CountNumbersUntil(midValue, N);

		if (countNumsUntilMidValue < k)
			minValue = midValue + 1;
		else
		{
			maxValue = midValue - 1;
			answer = min(answer, midValue);
		}
	}

	cout << answer;
	return 0;
}