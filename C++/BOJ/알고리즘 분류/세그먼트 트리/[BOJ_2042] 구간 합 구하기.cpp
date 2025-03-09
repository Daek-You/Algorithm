#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using int64 = long long;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int64> OrigialArray;
vector<int64> SegmentTree;

int64 Init(int64 currentNodeIndex, int64 startIndex, int64 lastIndex)
{
    if (startIndex == lastIndex)
    {
        SegmentTree[currentNodeIndex] = OrigialArray[startIndex];
        return SegmentTree[currentNodeIndex];
    }

    int64 midIndex = (startIndex + lastIndex) / 2;
    int64 leftChildIndex = currentNodeIndex * 2, rightChildIndex = currentNodeIndex * 2 + 1;

    int64 leftSum = Init(leftChildIndex, startIndex, midIndex);
    int64 rightSum = Init(rightChildIndex, midIndex + 1, lastIndex);
    SegmentTree[currentNodeIndex] = leftSum + rightSum;

    return SegmentTree[currentNodeIndex];
}

int64 FindSum(int64 currentNodeIndex, int64 startIndex, int64 lastIndex, int64 left, int64 right)
{
    if (right < startIndex or lastIndex < left)
        return 0;

    if (left <= startIndex and lastIndex <= right)
        return SegmentTree[currentNodeIndex];

    int64 midIndex = (startIndex + lastIndex) / 2;
    int64 leftChildIndex = currentNodeIndex * 2, rightChildIndex = currentNodeIndex * 2 + 1;

    int64 leftSum = FindSum(leftChildIndex, startIndex, midIndex, left, right);
    int64 rightSum = FindSum(rightChildIndex, midIndex + 1, lastIndex, left, right);

    return leftSum + rightSum;
}

void Update(int64 currentNodeIndex, int64 targetIndex, int64 startIndex, int64 lastIndex, int64 difference)
{
    if (targetIndex < startIndex or lastIndex < targetIndex)
        return;

    SegmentTree[currentNodeIndex] += difference;

    if (startIndex == lastIndex)
        return;

    int64 midIndex = (startIndex + lastIndex) / 2;
    int64 leftChildIndex = currentNodeIndex * 2, rightChildIndex = currentNodeIndex * 2 + 1;
    Update(leftChildIndex, targetIndex, startIndex, midIndex, difference);
    Update(rightChildIndex, targetIndex, midIndex + 1, lastIndex, difference);
}

int main()
{
    FAST_IO
    int64 N, M, K;
    cin >> N >> M >> K;

    OrigialArray.resize(N);
    for (int i = 0; i < N; i++)
        cin >> OrigialArray[i];

    int64 treeHeight = static_cast<int64>(ceil(log2(N)));
    int64 treeSize = 1 << (treeHeight + 1);

    SegmentTree.resize(treeSize);
    Init(1, 0, N - 1);

    int64 a, b, c;
    while (M > 0 or K > 0)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            int64 difference = c - OrigialArray[b - 1];
            OrigialArray[b - 1] = c;

            Update(1, b - 1, 0, N - 1, difference);
            M--;
            continue;
        }

        int64 sum = FindSum(1, 0, N - 1, b - 1, c - 1);
        cout << sum << "\n";
        K--;
    }

    return 0;
}