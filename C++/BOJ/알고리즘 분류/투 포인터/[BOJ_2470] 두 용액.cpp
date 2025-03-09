#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 2000000000

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> characteristicValues(N);
    for (int i = 0; i < N; i++)
        cin >> characteristicValues[i];
    
    sort(characteristicValues.begin(), characteristicValues.end());
    int start = 0, end = N - 1, standardValue = INF;
    pair<int, int> answer(INF, INF);

    while (start < end)
    {
        int compositeValue = characteristicValues[start] + characteristicValues[end];
        int absCompositeValue = abs(compositeValue);

        if (absCompositeValue < standardValue)
        {
            standardValue = absCompositeValue;
            answer.first = characteristicValues[start];
            answer.second = characteristicValues[end];

            if (absCompositeValue == 0)
                break;
        }

        if (compositeValue > 0)
            end--;
        if (compositeValue < 0)
            start++;
    }

    cout << answer.first << " " << answer.second;
    return 0;
}