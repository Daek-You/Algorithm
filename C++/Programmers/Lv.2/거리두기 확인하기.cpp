#include <string>
#include <vector>
using namespace std;
const char CANDIDATE = 'P';
const char PARTITION = 'X';
const int MAX_MANHATTAN_DISTANCE = 2;

vector<pair<int, int>> GetCandidatePositions(const vector<string>& waitingRoom) {
    vector<pair<int, int>> results;

    for (int row = 0; row < waitingRoom.size(); row++) {
        for (int col = 0; col < waitingRoom[0].length(); col++) {
            if (waitingRoom[row][col] == CANDIDATE)
                results.push_back(make_pair(row, col));
        }
    }

    return results;
}

int CalculateManhattanDistance(pair<int, int> pos1, pair<int, int> pos2) {
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

void Combination(const vector<string>& waitingRoom, const vector<pair<int, int>>& candidatePositions, vector<pair<int, int>>& candidates, int currentIdx, bool& result) {
    if (candidates.size() == 2) {
        int manhattanDistance = CalculateManhattanDistance(candidates[0], candidates[1]);

        if (manhattanDistance > MAX_MANHATTAN_DISTANCE)
            return;

        if (manhattanDistance < MAX_MANHATTAN_DISTANCE) {
            result = false;
            return;
        }

        if (manhattanDistance == MAX_MANHATTAN_DISTANCE) {
            bool isEqualRow = candidates[0].first == candidates[1].first;
            bool isEqualCol = candidates[0].second == candidates[1].second;
            
            int minRow = isEqualRow ? -1 : candidates[0].first < candidates[1].first ? candidates[0].first : candidates[1].first;
            int minCol = isEqualCol ? -1 : candidates[0].second < candidates[1].second ? candidates[0].second : candidates[1].second;

            // 가로로 한 칸 띄어져 있는 경우
            if (isEqualRow and minCol != -1) {
                int row = candidates[0].first;

                if (waitingRoom[row][minCol + 1] != PARTITION)
                    result = false;
                return;
            }

            // 세로로 한 칸 띄어져 있는 경우
            if (isEqualCol and minRow != -1) {
                int col = candidates[0].second;

                if (waitingRoom[minRow + 1][col] != PARTITION)
                    result = false;
                return;
            }

            // 대각선으로 한 칸 띄어져 있는 경우 (r1, c1), (r2, c2)라고 한다면,
            // 양 옆 테이블 좌표는 [r1][c2], [r2][c1]
            if ((!isEqualRow and !isEqualCol) and (waitingRoom[candidates[0].first][candidates[1].second] != PARTITION or waitingRoom[candidates[1].first][candidates[0].second] != PARTITION)) {
                result = false;
            }
        }

        return;
    }

    for (int i = currentIdx; i < candidatePositions.size(); i++) {
        if (!result)
            break;

        candidates.push_back(candidatePositions[i]);
        Combination(waitingRoom, candidatePositions, candidates, i + 1, result);
        candidates.pop_back();
    }
}

bool DoWellCovidDistance(const vector<string>& waitingRoom, const vector<pair<int, int>>& candidatePositions) {
    bool result = true;
    vector<pair<int, int>> candidates;

    Combination(waitingRoom, candidatePositions, candidates, 0, result);
    return result;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (const auto waitingRoom : places) {
        vector<pair<int, int>> candidatePositions = GetCandidatePositions(waitingRoom);
        bool doWellCovidDistance = DoWellCovidDistance(waitingRoom, candidatePositions);
        answer.push_back(doWellCovidDistance);
    }

    return answer;
}