#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int li = 0;                    // 몸무게 작은 사람 index
    int hi = people.size() - 1;    // 몸무게 많은 사람 index

    while (li <= hi) {
        if (li == hi) {
            answer++;
            break;            
        }
        
        else if (people[li] + people[hi] <= limit) {
            answer++;
            li++;
            hi--;
        }
        
        else {
            answer++;
            hi--;
        }
    }

    return answer;
}