#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_DISTANCE = 10000000;

int GetSquareDistance(int x1, int y1, int x2, int y2)
{
    return pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2);
}

int GetMinDistance(int startX, int startY, int targetX, int targetY, int m, int n)
{
    vector<int> distances (4, MAX_DISTANCE);

    // top
    if (!(startX == targetX and startY < targetY))
        distances[0] = GetSquareDistance(startX, n + (n - startY), targetX, targetY);

    // down
    if (!(startX == targetX and startY > targetY))
        distances[1] = GetSquareDistance(startX, -startY, targetX, targetY);

    // left
    if (!(startY == targetY and startX > targetX))
        distances[2] = GetSquareDistance(-startX, startY, targetX, targetY);

    // right
    if (!(startY == targetY and startX < targetX))
        distances[3] = GetSquareDistance(m + (m - startX), startY, targetX, targetY);

    return *min_element(distances.begin(), distances.end());;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (const auto& ball : balls)
    {
        int minDistance = GetMinDistance(startX, startY, ball[0], ball[1], m, n);
        answer.emplace_back(minDistance);
    }

    return answer;
}