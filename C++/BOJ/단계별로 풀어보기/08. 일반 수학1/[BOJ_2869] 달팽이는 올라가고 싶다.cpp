#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned int topHeight;          // 정상 높이(V미터)
	unsigned int climbingHeight;     // 낮에 올라가는 A미터
	unsigned int slipHeight;         // 밤에 미끄러지는 B미터

	cin >> climbingHeight >> slipHeight >> topHeight;

	/*
		낮을 기준으로만 보면 되기 때문에, 첫째날 낮, 둘째날 낮, ... 이런 식으로 보면 된다.
		n번째 낮에 달팽이가 올라간 높이 : (n * 낮에 올라가는 A미터) - (n - 1) * 밤에 미끄러지는 B미터

		즉, 우리가 세울 수 있는 방정식은 다음과 같다.
			정상높이 <= (n * 낮에 올라가는 A미터) - (n - 1) * 밤에 미끄러지는 B미터


		코드로 바꾸면,
			topHeight <= days * climbingHeight - (days - 1) * slipHeight;

		우리는 days를 구하는 것이기 때문에 days를 기준으로 식을 정리하면 된다.
			1) topHeight <= days * climbingHeight - days * slipHeight + slipHeight;
			2) topHeight - slipHeight <= days * (climbingHeight - slipHeight);
		
		따라서, 다음 식으로 정리할 수 있다.
			(topHeight - slipHeight) / (climbingHeight - slipHeight) <= days;

		위 식에 대입하여 나온 days 값을 소수점 첫째자리에서 올림처리하면 정답을 구할 수 있다.
	*/

	unsigned int days = 1;
	double result = static_cast<double>((topHeight - slipHeight)) / (climbingHeight - slipHeight);   // 소수점도 계산하기 위해 한 쪽을 실수형으로
	days = static_cast<unsigned int>(ceil(result));

	cout << days;
	return 0;
}