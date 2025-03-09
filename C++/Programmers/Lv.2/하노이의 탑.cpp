#include <vector>
using namespace std;

void Move(vector<vector<int>>& answers, int from, int to) {
    vector<int> log { from, to };
    answers.emplace_back(log);
}

void HanoiTower(vector<vector<int>>& answers, int start, int by, int destination, int n) {
    if (n == 1) {    // n번째 원판 옮기기
        Move(answers, start, destination);
        return;
    }

    by = 6 - destination - start;

    HanoiTower(answers, start, destination, by, n - 1);       // 1 ~ (n-1)번째 원판을 경유지에 옮기기
    Move(answers, start, destination);
    HanoiTower(answers, by, start, destination, n - 1);       // 경유지에 둔 원판들을 목적지로 옮기기
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    HanoiTower(answer, 1, 2, 3, n);
    return answer;
}