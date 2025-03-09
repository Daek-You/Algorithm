#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> drawingPaper(100, vector<int>(100, 0));
	int coloredPaperNums;
	cin >> coloredPaperNums;

	for (int i = 0; i < coloredPaperNums; i++)
	{
		int leftDistance, downDistance;
		cin >> leftDistance >> downDistance;

		for (int row = leftDistance; row < leftDistance + 10; row++)
		{
			for (int col = downDistance; col < downDistance + 10; col++)
			{
				drawingPaper[row][col] = 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (drawingPaper[i][j] == 1)
				answer++;
		}
	}

	cout << answer;
	return 0;
}