#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000001

vector<int> SegmentTree;
vector<int> Array;

int CreateMinSegmentTree(int node, int start, int last)
{
    if (start == last)
        return SegmentTree[node] = Array[start];

    int mid = (start + last) / 2;
    int leftChild = node * 2, rightChild = node * 2 + 1;

    int leftChildMinInteger = CreateMinSegmentTree(leftChild, start, mid);
    int rightChildMinInteger = CreateMinSegmentTree(rightChild, mid + 1, last);

    return SegmentTree[node] = min(leftChildMinInteger, rightChildMinInteger);
}

int FindMinInteger(int node, int start, int last, int left, int right)
{
    if (last < left or right < start)
        return INF;
    
    if (left <= start and last <= right)
        return SegmentTree[node];
    
    int mid = (start + last) / 2;
    int leftChild = node * 2, rightChild = node * 2 + 1;

    int leftMinInteger = FindMinInteger(leftChild, start, mid, left, right);
    int rightMinInteger = FindMinInteger(rightChild, mid + 1, last, left, right);

    return min(leftMinInteger, rightMinInteger);
}

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    Array.resize(N);
    for (int i = 0; i < N; i++)
        cin >> Array[i];
    
    int treeHeight = static_cast<int>(ceil(log2(N)));
    int treeSize = 1 << (treeHeight + 1);

    SegmentTree.resize(treeSize);
    CreateMinSegmentTree(1, 0, N - 1);

    int from, to;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        int minInteger = FindMinInteger(1, 0, N - 1, from - 1, to - 1);
        cout << minInteger << "\n";
    }

    return 0;
}