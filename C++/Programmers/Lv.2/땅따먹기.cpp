#include <vector>
#include <algorithm>
using namespace std;

int GetMaxValue(const vector<int>& row, int exceptColumn) {
    int maxValue = 0;
    for (int i = 0; i < row.size(); i++) {
        if (exceptColumn == i)
            continue;
        maxValue = max(maxValue, row[i]);
    }

    return maxValue;
}

int solution(vector<vector<int>> land)
{
    vector<vector<int>> dp(1, vector<int>(land[0].begin(), land[0].end()));

    for (int row = 1; row < land.size(); row++) {
        vector<int> dpRow;

        for (int col = 0; col < land[row].size(); col++) {
            int preDpRowMaxValue = GetMaxValue(dp[row - 1], col);
            dpRow.emplace_back(preDpRowMaxValue + land[row][col]);
        }

        dp.emplace_back(dpRow);
    }

    int lastRow = dp.size() - 1;
    return *max_element(dp[lastRow].begin(), dp[lastRow].end());
}