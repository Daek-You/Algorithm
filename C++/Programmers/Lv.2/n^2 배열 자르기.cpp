#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int row = left / n;
    int col = left % n;
    int count = right - left + 1;

    for (int i = 0; i < count; i++) {
        int num = max(row + 1, col + 1);
        answer.push_back(num);
        col++;

        if (col == n) {
            row += 1;
            col = 0;
        }
    }

    return answer;
}