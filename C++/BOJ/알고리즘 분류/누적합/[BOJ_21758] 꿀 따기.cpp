#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> honeys(N);
    for (int i = 0; i < N; i++)
        cin >> honeys[i];

    vector<int> prefixSum(N);
    prefixSum[0] = honeys[0];
    for (int i = 1; i < N; i++)
        prefixSum[i] = prefixSum[i - 1] + honeys[i];

    int totalHoney = prefixSum[N - 1];
    int maxHoney = 0;

    // 벌통이 왼쪽 끝에 있는 경우
    for (int i = 1; i < N - 1; i++)
    {
        int honey = (totalHoney - honeys[0] - honeys[i]) + (totalHoney - prefixSum[i]);
        maxHoney = max(maxHoney, honey);
    }

    // 벌통이 오른쪽 끝에 있는 경우
    for (int i = 1; i < N - 1; i++)
    {
        int honey = (totalHoney - honeys[N - 1] - honeys[i]) + prefixSum[i - 1];
        maxHoney = max(maxHoney, honey);
    }

    // 벌통이 중간에 있는 경우
    for (int i = 1; i < N - 1; i++)
    {
        int honey = (prefixSum[i] - honeys[0]) + (totalHoney - prefixSum[i - 1] - honeys[N - 1]);
        maxHoney = max(maxHoney, honey);
    }

    cout << maxHoney;
    return 0;
}
