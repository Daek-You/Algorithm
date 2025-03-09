#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int CreateSegmentTree(const vector<int>& numbers, vector<int>& tree, int node, int start, int end)
{
    if (start == end)
    {
        if (numbers[start] == 0)
            return tree[node] = 0;
        return tree[node] = (numbers[start] > 0) ? 1 : -1;
    }

    int mid = (start + end) / 2;
    int leftChild = node * 2, rightChild = node * 2 + 1;

    int leftSign = CreateSegmentTree(numbers, tree, leftChild, start, mid);
    int rightSign = CreateSegmentTree(numbers, tree, rightChild, mid + 1, end);

    return tree[node] = leftSign * rightSign;
}

int Update(vector<int>& tree, int target, int node, int start, int end, int sign)
{
    if (target < start or end < target)
        return tree[node];

    if (start == end)
        return tree[node] = sign;

    int mid = (start + end) / 2;
    int leftChild = node * 2, rightChild = node * 2 + 1;

    int leftSign = Update(tree, target, leftChild, start, mid, sign);
    int rightSign = Update(tree, target, rightChild, mid + 1, end, sign);
    return tree[node] = leftSign * rightSign;
}

int Multiply(const vector<int>& tree, int node, int start, int end, int left, int right)
{
    if (end < left or right < start)
        return 1;

    if (left <= start and end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int leftChild = node * 2, rightChild = node * 2 + 1;

    int leftSign = Multiply(tree, leftChild, start, mid, left, right);
    int rightSign = Multiply(tree, rightChild, mid + 1, end, left, right);
    return leftSign * rightSign;
}

int main()
{
    FAST_IO
        int N, K;

    // 1. 유효한 N, K 값을 읽었을 경우에만 실행
    while (cin >> N and cin >> K)
    {
        // 2. 주어진 수열들을 vector에 저장
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            cin >> numbers[i];

        // 3. 세그먼트 트리 생성
        int treeHeight = static_cast<int>(ceil(log2(N)));
        int treeSize = 1 << (treeHeight + 1);

        vector<int> segmentTree(treeSize);
        CreateSegmentTree(numbers, segmentTree, 1, 0, N - 1);

        // 4. 명령어 수행
        char instruction;
        int i, j;

        while (K--)
        {
            cin >> instruction >> i >> j;
            
            if (instruction == 'C')
            {
                if (j == 0)
                    numbers[i - 1] = 0;
                else
                    numbers[i - 1] = (j > 0) ? 1 : -1;
                Update(segmentTree, i - 1, 1, 0, N - 1, numbers[i - 1]);
            }

            else if (instruction == 'P')
            {
                int result = Multiply(segmentTree, 1, 0, N - 1, i - 1, j - 1);
                if (result == 0)
                {
                    cout << result;;
                    continue;
                }

                char signResult = (result > 0) ? '+' : '-';
                cout << signResult;;
            }
        }

        cout <<"\n";
    }

    return 0;
}