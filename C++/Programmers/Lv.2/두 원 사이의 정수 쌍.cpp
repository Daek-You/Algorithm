#include <cmath>
#include <algorithm>
using namespace std;

long long GetYValue(long long x, long long r, bool onCeil) {
    double y = sqrt(r * r - x * x);
    return onCeil ? ceil(y) : floor(y);
}

long long solution(int r1, int r2) {
    if (r1 < r2)      // r1이 더 큰 원이라고 가정
        swap(r1, r2);
    long long answer = 0;
    long long overlapPoints = (r1 - r2 + 1) * 4;

    // 2사분면 내(x, y축 제외) 점 개수 구하기
    for (int x = -r1 + 1; x < 0; x++) {
        long long r1Y = GetYValue(x, r1, false);

        // x <= -r2인 경우에는 y = 0 점을 제외시키도록 1로 설정
        long long r2Y = (x > -r2) ? GetYValue(x, r2, true) : 1;
        long long upperPointCount = r1Y - r2Y + 1;
        answer += upperPointCount;
    }

    return answer * 4 + overlapPoints;
}