#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<pair<int, int>> _stack;   // <숫자, 인덱스>
    _stack.push(make_pair(numbers[0], 0));
    
    for(int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] <= _stack.top().first) {
            _stack.push(make_pair(numbers[i], i));
            continue;
        }
        
        int pivot = numbers[i];
        
        while(!_stack.empty() and _stack.top().first < pivot)
        {
            int index = _stack.top().second;
            numbers[index] = pivot;
            _stack.pop();
        }
        
        _stack.push(make_pair(pivot, i));
    }
    
    // 뒷 큰수가 없는 숫자들 -1로 변경
    while(!_stack.empty()) {
        auto element = _stack.top();
        numbers[element.second] = -1;
        _stack.pop();
    }
    
    return numbers;
}