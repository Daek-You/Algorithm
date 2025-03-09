#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const pair<int, int>& n1, const pair<int, int>& n2) {
    int n1Difference = abs(n1.first - n1.second);
    int n2Difference = abs(n2.first - n2.second);

    if (n1Difference == n2Difference)
        return n1.first < n2.first;
    return n1Difference < n2Difference;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<pair<int, int>> candidates;
    int startIdx = 0, lastIdx = 0;
    int sum = 0;

    while (startIdx <= lastIdx and lastIdx < sequence.size()) {
        int nextSum = sum + sequence[lastIdx];
        
        if (nextSum == k)
            candidates.emplace_back(startIdx, lastIdx);

        if (nextSum < k)
            sum += sequence[lastIdx++];
        else
            sum -= sequence[startIdx++];
    }

    sort(candidates.begin(), candidates.end(), Compare);
    vector<int> answer {candidates[0].first, candidates[0].second};
    return answer;
}