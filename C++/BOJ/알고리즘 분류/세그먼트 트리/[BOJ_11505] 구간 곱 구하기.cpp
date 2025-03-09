#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using int64 = long long;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define DIVISOR 1000000007LL

vector<int64> Array;
vector<int64> SegmentTree;

int64 CreateSegmentTree(int64 node, int64 start, int64 last)
{
    if (start == last)
        return SegmentTree[node] = Array[start];
    
    int64 mid = (start + last) / 2;
    int64 leftChild = node * 2, rightChild = node * 2 + 1;

    int64 leftValue = CreateSegmentTree(leftChild, start, mid);
    int64 rightValue = CreateSegmentTree(rightChild, mid + 1, last);
    int64 result = (leftValue * rightValue) % DIVISOR;

    return SegmentTree[node] = result; 
}

int64 Update(int64 node, int64 target, int64 start, int64 last, int64 changedValue)
{
    if (last < target or target < start)
        return SegmentTree[node];

    if (start == last)
        return SegmentTree[node] = changedValue;

    int64 mid = (start + last) / 2;
    int64 leftChild = node * 2, rightChild = node * 2 + 1;
    
    int64 leftValue = Update(leftChild, target, start, mid, changedValue);
    int64 rightValue = Update(rightChild, target, mid + 1, last, changedValue);

    return SegmentTree[node] = (leftValue * rightValue) % DIVISOR; 
}

int64 FindMultiply(int64 node, int64 start, int64 last, int64 left, int64 right)
{
    if (last < left or right < start)
        return 1;
    
    if (left <= start and last <= right)
        return SegmentTree[node];
    
    int64 mid = (start + last) / 2;
    int64 leftChild = node * 2, rightChild = node * 2 + 1;

    int64 leftValue = FindMultiply(leftChild, start, mid, left, right);
    int64 rightValue = FindMultiply(rightChild, mid + 1, last, left, right);
    return (leftValue * rightValue) % DIVISOR;
}

int main()
{
    FAST_IO
    int N, M, K;
    cin >> N >> M >> K;

    Array.resize(N);
    for (int i = 0; i < N; i++)
        cin >> Array[i];
    
    int treeHeight = static_cast<int>(ceil(log2(N)));
    int treeSize = 1 << (treeHeight + 1);

    SegmentTree.resize(treeSize);
    CreateSegmentTree(1, 0, N - 1);

    int64 a, b, c;
    while (M > 0 or K > 0)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            Array[b - 1] = c;
            Update(1, b - 1, 0, N - 1, c);
            M--;
            continue;
        }

        int64 answer = FindMultiply(1, 0, N - 1, b - 1, c - 1);
        cout << answer << "\n";
        K--;
    }

    return 0;
}