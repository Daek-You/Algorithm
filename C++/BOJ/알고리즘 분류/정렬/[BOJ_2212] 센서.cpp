#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N, K;
    cin >> N >> K;

    vector<long long> sensors(N);
    for (int i = 0; i < N; i++)
        cin >> sensors[i];

    sort(sensors.begin(), sensors.end());
    vector<long long> emptySpaces(N - 1);

    for (int i = 0; i < N - 1; i++)
        emptySpaces[i] = sensors[i + 1] - sensors[i];

    sort(emptySpaces.begin(), emptySpaces.end(), greater<int>());
    long long answer = 0;

    for (int i = K - 1; i < N - 1; i++)
        answer += emptySpaces[i];

    cout << answer;
    return 0;
}