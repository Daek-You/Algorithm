#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N;
    cin >> N;

    // 1. N까지의 모든 소수 구하기 (에라토스테네스의 체)
    vector<bool> isPrimeNumbers(N + 1, true);
    isPrimeNumbers[0] = isPrimeNumbers[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (isPrimeNumbers[i])
        {
            for (int k = i * i; k <= N; k += i)
                isPrimeNumbers[k] = false;
        }
    }

    // 2. 소수로 이루어진 누적합 배열 만들기
    vector<int> accumulatedPrimeNumbers { 0 };
    for (int i = 2; i <= N; i++)
        if (isPrimeNumbers[i])
            accumulatedPrimeNumbers.push_back(accumulatedPrimeNumbers.back() + i);

    // 3. 투 포인터를 통해, 조건에 부합하는 수의 경우의 수 찾기
    int left = 0, right = 1, end = accumulatedPrimeNumbers.size() - 1, answer = 0;
    while (left < end)
    {
        while (right < end and accumulatedPrimeNumbers[right] - accumulatedPrimeNumbers[left] < N)
            right++;

        while (left < right and accumulatedPrimeNumbers[right] - accumulatedPrimeNumbers[left] >= N)
        {
            if (accumulatedPrimeNumbers[right] - accumulatedPrimeNumbers[left] == N)
                answer++;
            left++;
        }

        // right를 끝까지 다 보냈는데 연속합이 N보다 작은 경우, 루프를 끝내주기 위해 left++
        if (right == end)
            left++;
    }

    cout << answer;
    return 0;
}