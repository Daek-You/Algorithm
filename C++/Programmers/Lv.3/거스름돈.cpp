#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int solution(int n, vector<int> money)
{
    sort(money.begin(), money.end());
    vector<int> DP(n + 1, 0);
    DP[0] = 1;

    for (const int monetaryUnit : money)
    {
        for (int currentCost = 1; currentCost <= n; currentCost++)
        {
            if (currentCost < monetaryUnit) continue;
            DP[currentCost] = (DP[currentCost] + DP[currentCost - monetaryUnit]) % MOD;
        }
    }

    return DP[n];
}