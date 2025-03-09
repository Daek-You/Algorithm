#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindMaxCandyCount(vector<vector<int>>& maze, int N, int M)
{
	// 0행 누적합 적용
	for (int row = 1; row < N; row++)
		maze[row][0] += maze[row - 1][0];

	// 0열 누적합 적용
	for (int col = 1; col < M; col++)
		maze[0][col] += maze[0][col - 1];

	// {위쪽, 왼쪽, 대각선 왼쪽 위} 중에 제일 큰 수와 현재 수를 더해서 저장
	for (int row = 1; row < N; row++)
		for (int col = 1; col < M; col++)
			maze[row][col] += max({ maze[row - 1][col], maze[row][col - 1], maze[row - 1][col - 1] });
	return maze[N - 1][M - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> maze(N, vector<int>(M));
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> maze[r][c];

	int answer = FindMaxCandyCount(maze, N, M);
	cout << answer;
	return 0;
}
