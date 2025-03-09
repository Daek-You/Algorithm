#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using int64 = long long;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int64> Numbers;
vector<int64> SegmentTree;

int64 CreateSegmentTree(int currentNode, int start, int last)
{
    if (start == last)
        return SegmentTree[currentNode] = Numbers[start];

    int mid = (start + last) / 2;
    int leftChild = currentNode * 2, rightChild = currentNode * 2 + 1;

    int64 leftSum = CreateSegmentTree(leftChild, start, mid);    
    int64 rightSum = CreateSegmentTree(rightChild, mid + 1, last);

    return SegmentTree[currentNode] = leftSum + rightSum;
}

int64 GetSum(int currentNode, int start, int last, int left, int right)
{
    // 찾고자 하는 구간과 전혀 상관없는 구간인 경우
    if (last < left or right < start)
        return 0;
    
    // 찾고자 하는 구간이 포함된 경우
    if (left <= start and last <= right)
        return SegmentTree[currentNode];
    
    // 찾고자 하는 구간에 대해 더 탐색이 필요한 경우
    int mid = (start + last) / 2;
    int leftChild = currentNode * 2, rightChild = currentNode * 2 + 1;

    int64 leftSum = GetSum(leftChild, start, mid, left, right);
    int64 rightSum = GetSum(rightChild, mid + 1, last, left, right);
    return leftSum + rightSum;
}

void Update(int currentNode, int targetNode, int start, int last, int64 difference)
{
    if (targetNode < start or last < targetNode)
        return;
    
    SegmentTree[currentNode] += difference;
    
    if (start == last)
        return;
    
    int mid = (start + last) / 2;
    int leftChild = currentNode * 2, rightChild = currentNode * 2 + 1;

    Update(leftChild, targetNode, start, mid, difference);
    Update(rightChild, targetNode, mid + 1, last, difference);
}

int main()
{
    FAST_IO
    int numberCount, turnCount;
    cin >> numberCount >> turnCount;

    // 1. 배열 초기화
    Numbers.resize(numberCount);
    for (int i = 0; i < numberCount; i++)
        cin >> Numbers[i];
    
    // 2. 세그먼트 트리 생성
    int treeHeight = static_cast<int>(ceil(log2(numberCount)));
    int treeSize = 1 << (treeHeight + 1);
    
    SegmentTree.resize(treeSize);
    CreateSegmentTree(1, 0, numberCount - 1);

    // 3. 게임 시작
    int from, to, before;
    int64 after;

    for (int i = 0; i < turnCount; i++)
    {
        cin >> from >> to >> before >> after;

        if (from > to)
            swap(from, to);

        int64 sum = GetSum(1, 0, numberCount - 1, from - 1, to - 1);
        cout << sum << "\n";

        int64 difference = after - Numbers[before - 1];
        Numbers[before - 1] = after;
        Update(1, before - 1, 0, numberCount - 1, difference);
    }

    return 0;
}