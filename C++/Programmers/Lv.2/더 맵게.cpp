#include <string>
#include <vector>
#include <queue>
using namespace std;
using LL = long long;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<LL, vector<LL>, greater<LL>> scovilles;
    
    for (const auto element : scoville)
        scovilles.emplace(element);
    

    while (scovilles.size() >= 2) {
        LL leastSpicyFood = scovilles.top();
        scovilles.pop();

        LL secondLeastSpicyFood = scovilles.top();
        scovilles.pop();

        if (leastSpicyFood >= K)
            break;

        LL newScovill = leastSpicyFood + secondLeastSpicyFood * 2;
        answer++;
        scovilles.emplace(newScovill);
    }

    if (scovilles.top() < K)
        return -1;

    return answer;
}