#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using uint32 = unsigned int;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<uint32> OriginalArray, LeftArray, RightArray;

void Combination(vector<uint32>& array, uint32 start, uint32 end, uint32 sum, uint32 targetValue)
{
    if (sum > targetValue)
        return;

    if (start >= end)
    {
        array.push_back(sum);
        return;
    }

    Combination(array, start + 1, end, sum, targetValue);                // 현재 물건을 포함하지 않는 경우
    Combination(array, start + 1, end, sum + OriginalArray[start], targetValue); // 현재 물건을 포함하는 경우
}

int main()
{
    FAST_IO
    uint32 N, C;
    cin >> N >> C;

    OriginalArray.resize(N);
    for (uint32 i = 0; i < N; i++)
        cin >> OriginalArray[i];
    
    Combination(LeftArray, 0, N / 2, 0, C);
    Combination(RightArray, N / 2, N, 0, C);
    sort(RightArray.begin(), RightArray.end());

    uint32 answer = 0;
    for (const uint32& leftElement : LeftArray)
    {
        int rightValue = C - leftElement;
        answer += upper_bound(RightArray.begin(), RightArray.end(), rightValue) - RightArray.begin();
    }

    cout << answer;
    return 0;
}