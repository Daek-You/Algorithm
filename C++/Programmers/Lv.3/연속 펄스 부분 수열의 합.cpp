#include <vector>
#include <cmath>

using namespace std;
using int64 = long long;

int64 FindLargestPulseSubsetSum(const vector<int64>& pulseSequence, int N, const int sign)
{
    int64 result = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = max(sum, 0LL) + pulseSequence[i] * sign;
        result = max(result, sum);
    }

    return result;
}

int64 solution(vector<int> sequence) {
    int N = sequence.size();
    vector<int64> pulseSequence(N);

    for (int i = 0; i < N; i++)
    {
        int sign = (i % 2 == 0) ? 1 : -1;
        pulseSequence[i] = sign * sequence[i];
    }

    int64 answer = FindLargestPulseSubsetSum(pulseSequence, N, 1);
    answer = max(answer, FindLargestPulseSubsetSum(pulseSequence, N, -1));
    return answer;
}