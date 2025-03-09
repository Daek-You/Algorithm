#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> cummulativeSum { 0.0 };
    
    while (true) {
        int nextK = (k % 2 == 0) ? k / 2 : (k * 3) + 1;
        double area = static_cast<double>(k + nextK) / 2;
        cummulativeSum.emplace_back(cummulativeSum.back() + area);
        k = nextK;

        if (k == 1)
            break;
    }
    
    vector<double> answer;

    for (const auto& range : ranges) {
        int leftX = range[0], rightX = cummulativeSum.size() - 1 + range[1];

        if (rightX < leftX) {
            answer.emplace_back(-1.0);
            continue;
        }

        double area = cummulativeSum[rightX] - cummulativeSum[leftX];
        answer.emplace_back(area);
    }

    return answer;
}