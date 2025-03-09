#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> priceStack;    // <주가, 스택 진입 시각>
    
    for (int second = 1; second <= prices.size(); second++) {
        int index = second - 1;

        if (priceStack.empty() or priceStack.top().first < prices[index]) {
            priceStack.emplace(prices[index], second);
            continue;
        }

        while (!priceStack.empty()) {
            pair<int, int> top = priceStack.top();
            
            if (top.first <= prices[index])
                break;
            
            int holdingTime = second - top.second;
            int targetIdx = top.second - 1;
            answer[targetIdx] = holdingTime;
            priceStack.pop();
        }

        priceStack.emplace(prices[index], second);
    }

    while (!priceStack.empty()) {
        int holdingTime = prices.size() - priceStack.top().second;
        int targetIdx = priceStack.top().second - 1;
        answer[targetIdx] = holdingTime;
        priceStack.pop();
    }
    
    return answer;
}