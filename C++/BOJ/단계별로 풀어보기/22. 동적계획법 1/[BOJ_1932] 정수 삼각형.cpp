#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void CalculateSum(vector<vector<int>>& triangle, int currentRow, int N)
{
	if (currentRow == N)
		return;

	for (int i = 0; i < triangle[currentRow].size(); i++)
	{
		int previousRow = currentRow - 1;
		int leftPathSum = -1, rightPathSum = -1;

		// 왼쪽 위의 부모가 있을 경우
		if (i - 1 >= 0)
			leftPathSum = triangle[currentRow][i] + triangle[previousRow][i - 1];
		
		// 오른쪽 위의 부모가 있을 경우
		if (i < triangle[previousRow].size())
			rightPathSum = triangle[currentRow][i] + triangle[previousRow][i];

		triangle[currentRow][i] = max(leftPathSum, rightPathSum);
	}

	CalculateSum(triangle, currentRow + 1, N);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	/* --------------------- input ---------------------*/
	int N;
	cin >> N;
	vector<vector<int>> triangle(N);
	
	for (int row = 0; row < N; row++)
	{
		vector<int> elements(row + 1);

		for (int i = 0; i < row + 1; i++)
			cin >> elements[i];
		triangle[row] = elements;
	}
	/* -------------------------------------------------*/

	CalculateSum(triangle, 1, N);
	cout << *max_element(triangle[N - 1].begin(), triangle[N - 1].end());
	return 0;
}
