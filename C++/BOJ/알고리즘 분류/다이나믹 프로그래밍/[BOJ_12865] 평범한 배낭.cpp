#include <iostream>
#include <vector>

using namespace std;
using Data = pair<int, int>;    // <무게, 가치>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int itemCount, maxWeight;
    cin >> itemCount >> maxWeight;

    vector<Data> items(itemCount + 1);
    for (int i = 1; i <= itemCount; i++)
        cin >> items[i].first >> items[i].second;

    vector<vector<int>> dp(itemCount + 1, vector<int>(maxWeight + 1));
    for (int itemId = 1; itemId <= itemCount; itemId++)
    {
        for (int bagWeight = 1; bagWeight <= maxWeight; bagWeight++)
        {
            int itemWeight = items[itemId].first;
            int itemValue = items[itemId].second;

            if (bagWeight < itemWeight)
                dp[itemId][bagWeight] = dp[itemId - 1][bagWeight];
            else
                dp[itemId][bagWeight] = max(dp[itemId - 1][bagWeight], dp[itemId - 1][bagWeight - itemWeight] + itemValue);
        }
    }

    cout << dp[itemCount][maxWeight];
    return 0;
}