#include <vector>
using namespace std;
using Board = vector<vector<bool>>;

bool IsCorrectDeploying(const Board& board, int n, int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i][col])
			return false;

	/*  [Example]
		놓으려는 위치는 (3, 2)
		
		1? [  ][  ][ ][ ]
		   [2?][  ][ ][ ]
		   [  ][3?][ ][ ]
		   [  ][  ][o][ ]

		배치하려는 곳("o" 표시)의 행 인덱스 번호가 3이므로, 현재 열에서 3칸 떨어진 곳부터 위에서 보면서 내려와야 한다.
		가장 처음으로 볼 곳이 "1?"이고, 두 번재는 2?, ... 이런 식으로 간다.
		이것은 (배치하려는 행 - 검사하는 행)을 현재 배치하려는 열에서 빼거나 더한만큼과 같다.
		ex)
			2? 위치로 예를 들면,
			배치하려는 행(3) - 검사할 행(1) = 3이고, 배치하려는 열(2) - 2 = 0과 같다.
			이것이 2?의 열 인덱스가 된다.

		위와 같은 방식으로 진행하되, 왼쪽 대각선 위를 검사하려면 빼고, 오른쪽 대각선 위를 검사하라면 더하면 된다.
	*/

		int columnDifference = row - i;
		if (col - columnDifference >= 0 and board[i][col - columnDifference])
			return false;
		
		if (col + columnDifference < n and board[i][col + columnDifference])
			return false;
	}
	
	return true;
}


int DeployQueen(Board& board, int n, int row) {
	if (row == n)
		return true;

	int result = 0;
	for (int ci = 0; ci < n; ci++) {
		if (!IsCorrectDeploying(board, n, row, ci))
			continue;

		board[row][ci] = true;
		result += DeployQueen(board, n, row + 1);
		board[row][ci] = false;
	}

	return result;
}


int solution(int n) {
	Board board(n, vector<bool>(n, false));
	int answer = DeployQueen(board, n, 0);
	return answer;
}