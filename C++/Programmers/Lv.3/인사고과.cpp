#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> targetPoint = scores[0];

    sort(scores.begin(), scores.end(),
    [](const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    });

    int max = 0, answer = 1;
    for (const vector<int>& score : scores)
    {
        if (targetPoint[0] < score[0] and targetPoint[1] < score[1])
            return -1;
        
        if (max <= score[1])
        {
            max = score[1];
            
            if (targetPoint[0] + targetPoint[1] < score[0] + score[1])
                answer++;
        }
    }

    // [3,2] [3,2] [2,1] [2,2] [1,4]
    
    return answer;
}