#include <string>
#include <vector>
using namespace std;
using Position = pair<int, int>;
const int BOARD_LENGTH = 3;
// 좌우, 상하, y=-x 대각라인, y=x 대각라인
vector<vector<Position>> positionDirections { {{0, -1}, { 0, 1 }}, { {-1, 0}, { 1, 0} }, { {-1, -1}, { 1, 1} }, { {1, -1}, {-1, 1} } };


pair<vector<Position>, vector<Position>> GetPositions(const vector<string>& board) {
	vector<Position> firster;
	vector<Position> seconder;

	for (int row = 0; row < BOARD_LENGTH; row++) {
		for (int col = 0; col < BOARD_LENGTH; col++) {
			if (board[row][col] == 'O')
				firster.emplace_back(row, col);
			else if (board[row][col] == 'X')
				seconder.emplace_back(row, col);
		}
	}
	return make_pair(firster, seconder);
}

bool IsWin(const vector<string>& board, const vector<Position>& positions, char target) {
	for (const auto position : positions) {
		int currentRow = position.first;
		int currentCol = position.second;

		for (const auto& directions : positionDirections) {
			bool isWin = true;

			for (const auto& direction : directions) {
				int nextRow = currentRow + direction.first;
				int nextCol = currentCol + direction.second;

				if (nextRow < 0 or nextRow >= BOARD_LENGTH or nextCol < 0 or nextCol >= BOARD_LENGTH or board[nextRow][nextCol] != target)
					isWin = false;
			}

			if (isWin)
				return true;
		}
	}

	return false;
}

int solution(vector<string> board) {
	auto positions = GetPositions(board);
	vector<Position> firster = positions.first;
	vector<Position> seconder = positions.second;

	if (abs((int)firster.size() - (int)seconder.size()) > 1)
		return false;

	if (firster.size() < seconder.size())
		return false;

	bool isFirsterWin = IsWin(board, firster, 'O');
	bool isSeconderWin = IsWin(board, seconder, 'X');

	if (isFirsterWin and isSeconderWin)
		return false;

	if (isFirsterWin and firster.size() - seconder.size() <= 0)
		return false;

	if (isSeconderWin and firster.size() != seconder.size())
		return false;

	return true;
}