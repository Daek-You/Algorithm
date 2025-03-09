#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Line = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


int main()
{
    FAST_IO
    int N, L;
    cin >> N >> L;

    vector<Line> waterPools(N);
    for (int i = 0; i < N; i++) cin >> waterPools[i].first >> waterPools[i].second;

    sort(waterPools.begin(), waterPools.end());
    int position = 0;
    int answer = 0;

    for (const Line& waterPool : waterPools)
    {
        if (waterPool.second <= position)   continue;

        position = max(position, waterPool.first);
        int space = waterPool.second - position;
        int woods = space / L;

        if (space % L != 0) woods++;

        answer += woods;
        position += (L * woods);
    }

    cout << answer;
    return 0;
}