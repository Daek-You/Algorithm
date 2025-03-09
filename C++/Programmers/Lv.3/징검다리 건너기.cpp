#include <vector>
#include <algorithm>
using namespace std;

bool IsPossibleToCrossBridge(const vector<int>& stones, const int k, const int mid)
{
    int rockCount = 0;

    for (const int& stone : stones)
    {
        if (stone <= mid) rockCount++;
        else              rockCount = 0;

        if (k <= rockCount)
            return false;
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(), stones.end());

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (IsPossibleToCrossBridge(stones, k, mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}