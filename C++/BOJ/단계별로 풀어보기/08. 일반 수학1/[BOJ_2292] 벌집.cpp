#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	const int hexagonSideNums = 6;
	int startNum = 2;
	int distance = 1;

	while (true)
	{
		if (startNum > N)
			break;

		startNum += hexagonSideNums * distance;
		distance++;
	}

	cout << distance;
	return 0;
}