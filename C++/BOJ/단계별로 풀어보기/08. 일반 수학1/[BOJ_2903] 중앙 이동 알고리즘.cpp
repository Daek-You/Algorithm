#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	/*
		과정을 거칠 때마다 제일 바깥쪽 큰 정사각형의 한 변에 속해있는 점의 개수가 다음과 같이 늘어난다.
		0번째        | 1번째               |  2번째               | 3번째                 | 4번째
		  2            3(0번째 점 개수 + 1)   5(1번째 점 개수 + 2)   9(2번째 점 개수 + 4)    17(3번째 점 개수 + 8개)
		
		즉, 늘어가는 개수가 2배씩 커지는 등비수열의 형태
	*/

	int PointNumsOfSide = 2;   // 처음 제일 큰 정사각형의 한 변 점 개수 (2개)

	for (int i = 0; i < N; i++)
	{
		PointNumsOfSide += 1 << i;
	}

	cout << PointNumsOfSide * PointNumsOfSide;
	return 0;
}