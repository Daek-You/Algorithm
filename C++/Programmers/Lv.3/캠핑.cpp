#include <vector>
#include <algorithm>
using namespace std;
using Point = pair<int, int>;

bool IsValid(const vector<vector<int>>& data, int startIndex, int endIndex, int leftX, int leftY, int rightX, int rightY)
{
    for (int mid = startIndex; mid < endIndex; mid++)
    {
        int midX = data[mid][0], midY = data[mid][1];

        if ((leftX < midX and midX < rightX) and (min(leftY, rightY) < midY and midY < max(leftY, rightY)))
            return false;
    }

    return true;
}

bool IsZeroArea(int leftX, int leftY, int rightX, int rightY)
{
    return leftX == rightX or leftY == rightY;
}

int solution(int n, vector<vector<int>> data)
{
    int answer = 0;
    sort(data.begin(), data.end());

    for (int from = 0; from < n - 1; from++)
    {
        int leftX = data[from][0], leftY = data[from][1];

        for (int to = from + 1; to < n; to++)
        {
            int rightX = data[to][0], rightY = data[to][1];

            if (IsZeroArea(leftX, leftY, rightX, rightY))
                continue;
            
            if (IsValid(data, from + 1, to, leftX, leftY, rightX, rightY))
                answer++;
        }
    }

    return answer;
}