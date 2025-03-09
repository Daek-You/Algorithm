#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 2147000000

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> liquids(N);
    for (int i = 0; i < N; i++)
        cin >> liquids[i];

    pair<int, int> answer;
    int left = 0, right = N - 1;
    int minSum = INF;

    while (left < right)
    {
        int sum = liquids[left] + liquids[right];

        if (abs(sum) < minSum)
        {
            answer.first = liquids[left];
            answer.second = liquids[right];
            minSum = abs(sum);
        }

        if (sum < 0) left++;
        else         right--;
    }

    cout << answer.first << " " << answer.second;
    return 0;
}