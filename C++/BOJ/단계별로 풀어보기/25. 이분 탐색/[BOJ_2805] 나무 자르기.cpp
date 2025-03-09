#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using uint32 = unsigned int;

uint32 GetLongestTreeHeight(const vector<uint32>& trees, const int M)
{
    uint32 start = 1, last = trees.back();
    uint32 answer = 0;

    while (start <= last)
    {
        uint32 mid = (start + last) / 2;
        long long length = 0;

        for (const auto& tree : trees)
            length += (tree <= mid) ? 0 : tree - mid;

        if (length >= M)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
            last = mid - 1;
    }

    return answer;
}

int main()
{
    FAST_IO;

    int N, M;
    cin >> N >> M;

    vector<uint32> trees(N);
    for (int i = 0; i < N; i++)
        cin >> trees[i];

    sort(trees.begin(), trees.end());
    uint32 answer = GetLongestTreeHeight(trees, M);
    cout << answer;
    return 0;
}
