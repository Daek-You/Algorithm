#include <vector>
using namespace std;

void DFS(const vector<int>& numbers, const int& target, int sum, int idx, int& answer) {
    if (idx == numbers.size()) {
        if (sum == target)
            answer++;
        return;
    }

    DFS(numbers, target, sum + numbers[idx], idx + 1, answer);
    DFS(numbers, target, sum - numbers[idx], idx + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, 0, 0, answer);
    return answer;
}