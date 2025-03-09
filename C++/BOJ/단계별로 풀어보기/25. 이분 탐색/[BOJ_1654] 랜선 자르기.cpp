#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using uint32 = unsigned int;

uint32 FindLongestCableLength(const vector<int>& cables, const int N)
{
    uint32 start = 1, last = cables.back();
    uint32 answer = 0;

    while (start <= last)
    {
        uint32 mid = (start + last) / 2;
        uint32 count = 0;

        for (const auto& cable : cables)
            count += (cable / mid);

        if (count >= N)
        {
            answer = mid;
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

    int K, N;
    cin >> K >> N;

    vector<int> lanCables(K);
    for (int i = 0; i < K; i++)
        cin >> lanCables[i];

    sort(lanCables.begin(), lanCables.end());
    int answer = FindLongestCableLength(lanCables, N);

    cout << answer;
    return 0;
}
