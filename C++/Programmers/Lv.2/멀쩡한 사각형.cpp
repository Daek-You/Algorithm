#include <algorithm>
using namespace std;

/*
	- 직선의 기울기를 사용하여 처음에 도전하였으나, 부동소수점 이슈로 인해 실패
	- 이 문제는 알고보니, 최대공약수를 이용하여 푸는 문제였음
	- 못 쓰는 사각형들이 일정한 패턴으로 반복된다는 점은 인지하였으나, 그 부분을 이용하여 갈 생각을 못했던 것 같음
	- 다음에는 이런 부분도 신경 써 보자.

*/

long long solution(int w, int h) {
    long long gcdValue = __gcd(w, h);
    long long lw = static_cast<long long>(w), lh = static_cast<long long>(h); 
    long long area = lw * lh;
    
    return area - (lw + lh - gcdValue);
}
