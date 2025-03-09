#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int MAX_POSITION = 10000;
	int N;
	cin >> N;

	int minX = MAX_POSITION;
	int maxX = -MAX_POSITION;
	int minY = MAX_POSITION;
	int maxY = -MAX_POSITION;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}

	int width = maxX - minX;
	int height = maxY - minY;
	cout << width * height;
	
	return 0;
}