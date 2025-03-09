#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const vector<int>& m1, const vector<int>& m2) {
    if (m1[0] == m2[0])
        return m1[1] < m2[1];
    return m1[0] < m2[0];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), Compare);
    int currentEnd = 0, answer = 0;

    for (const auto& target : targets) {
        int start = target[0], end = target[1];

        if (currentEnd <= start) {
            answer++;
            currentEnd = end;
            continue;
        }
        
        currentEnd = min(currentEnd, end);
    }
    
    return answer;
}