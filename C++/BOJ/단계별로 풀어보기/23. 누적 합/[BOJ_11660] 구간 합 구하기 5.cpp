#include <iostream>
#include <vector>
#define FAST_IO cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int main()
{
	FAST_IO;

	int N, M;
	cin >> N >> M;

	vector<vector<int>> field(N + 1, vector<int>(N + 1));
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			// 1. 0행 0열 값은 그냥 저장하기
			if (row == 1 and col == 1)
			{
				cin >> field[row][col];
				continue;
			}

			int data;
			cin >> data;

			// 2. 0번째 행은 col - 1번째 값에다 새로운 데이터를 더해 누적하여 저장하기
			if (row == 1 and col > 1)
			{
				field[row][col] = field[row][col - 1] + data;
				continue;
			}

			// 3. 0번째 열은 row - 1번째 값에다 새로운 데이터를 더해 누적하여 저장하기
			if (col == 1 and row > 1)
			{
				field[row][col] = field[row - 1][col] + data;
				continue;
			}

			// 4. field[row][col] = [row - 1][col] + [row][col - 1] - [row - 1][col - 1] + data
			field[row][col] = field[row - 1][col] + field[row][col - 1] - field[row - 1][col - 1] + data;
		}
	}


	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// [x2, y2] 면적 - ([x1 - 1, y2] 까지의 면적) - ([x2, y1 - 1] 까지의 열 면적) + (앞에서 두 번 빼서 겹치는 부분)
		int answer = field[x2][y2] - field[x1 - 1][y2] - field[x2][y1 - 1] + field[x1 - 1][y1 - 1];
		cout << answer << "\n";
	}


	return 0;
}