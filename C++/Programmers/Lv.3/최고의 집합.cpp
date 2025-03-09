#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s)
{
    // 각 원소의 곱이 최대가 되려면 원소 간 차이가 최소화되어야 한다.
    
    if (n > s)
        return { -1 };
    
    int divisor = s / n;
    int remainder = s % n;
    
    vector<int> answers(n, divisor);
    int index = 0;
    
    while (remainder > 0)
    {
        answers[index]++;
        remainder--;
        index = (index + 1) % answers.size();
    }
    
    sort(answers.begin(), answers.end());
    return answers;
}