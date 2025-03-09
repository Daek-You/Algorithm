#include <iostream>
#include <cmath>

using namespace std;
#define EPSILON 0.000001

double CalculateIntersectionHeight(const double x, const double y, const double width)
{
    double leftBuildingHeight = sqrt(pow(x, 2) - pow(width, 2));
    double rightBuildingHeight = sqrt(pow(y, 2) - pow(width, 2));

    return (leftBuildingHeight * rightBuildingHeight) / (leftBuildingHeight + rightBuildingHeight);
}

int main()
{
    double x, y, c;
    cin >> x >> y >> c;

    double left = 0;
    double right = min(x, y);  // 빌딩 사이의 거리가 두 삼각형의 빗변보다는 작아야 한다.
    double answer = 0;

    while (right - left > EPSILON)
    {
        double mid = (left + right) / 2;
        double intersectionHeight = CalculateIntersectionHeight(x, y, mid);

        if (intersectionHeight < c)
            right = mid;
        else
        {
            answer = mid;
            left = mid;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << answer;
    return 0;
}
