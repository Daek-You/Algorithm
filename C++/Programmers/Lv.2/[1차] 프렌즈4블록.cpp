#include <string>
#include <vector>
using namespace std;
using Position = pair<int, int>;
vector<Position> directions { {0, 1}, {1, 0}, {1, 1} };
const char EMPTY = '#';

bool IsCanRemove(const vector<string>& board, int row, int col, int m, int n, char myCharacter) {
	if (board[row][col] == EMPTY)
		return false;

	for (int i = 0; i < directions.size(); i++) {
		int nextRow = row + directions[i].first;
		int nextCol = col + directions[i].second;

		if (nextRow < 0 or nextRow >= m or nextCol < 0 or nextCol >= n)
			return false;

		char symbol = board[nextRow][nextCol];

		if (symbol == EMPTY)
			return false;
		if (board[nextRow][nextCol] != myCharacter)
			return false;
	}
    
	return true;
}

void Remove(vector<string>& board, vector<Position> targets, int& removeCount) {
	for (const auto position : targets) {
		int row = position.first;
		int col = position.second;

		if (board[row][col] != EMPTY) {
			board[row][col] = EMPTY;
			removeCount++;
		}

		for (int i = 0; i < directions.size(); i++) {
			int nextRow = row + directions[i].first;
			int nextCol = col + directions[i].second;

			if (board[nextRow][nextCol] != EMPTY) {
				board[nextRow][nextCol] = EMPTY;
				removeCount++;
			}
		}
	}
}


void Replace(vector<string>& board, Position target, Position refillPos) {
	if (target.first < 0)
		return;

	int targetRow = target.first, targetCol = target.second;
	int refillRow = refillPos.first, refillCol = refillPos.second;
	Position newRefill = refillPos;

	if (board[targetRow][targetCol] != EMPTY) {
		board[refillRow][refillCol] = board[targetRow][targetCol];
		board[targetRow][targetCol] = EMPTY;
		newRefill = Position(refillRow - 1, refillCol);
	}

	Replace(board, Position(targetRow - 1, targetCol), newRefill);
}


void SlideToDown(vector<string>& board, int m, int n) {
	for (int col = 0; col < n; col++) {
		Position refillPos(-1, -1);
		Position target(-1, -1);
		int row = m - 1;

		// 채울 공간 찾기
		for (; row >= 0; row--) {
			if (board[row][col] == EMPTY) {
				refillPos = Position(row, col);
				row--;
				break;
			}
		}

		// 제일 먼저 내려올 애 찾기
		for (; row >= 0; row--) {
			if (board[row][col] != EMPTY) {
				target = Position(row, col);
				break;
			}
		}

		bool isExistTarget = (target.first != -1) and (target.second != -1);
		bool isExistRefillPlace = (refillPos.first != -1) and (refillPos.second != -1);

		if (isExistTarget and isExistRefillPlace)
			Replace(board, target, refillPos);
	}
}

int solution(int m, int n, vector<string> board) {
	bool isCanRemove = false;
	int answer = 0;

	do {
		isCanRemove = false;
		vector<Position> removeTargets;

		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				if (IsCanRemove(board, row, col, m, n, board[row][col])) {
					removeTargets.emplace_back(row, col);
					isCanRemove = true;
				}
			}
		}

		Remove(board, removeTargets, answer);
		SlideToDown(board, m, n);
	} while (isCanRemove);
	return answer;
}