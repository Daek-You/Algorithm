#include <vector>
#include <queue>
using namespace std;
using int64 = long long;

int64 SquareSum(priority_queue<int>& workPool)
{
    int64 sum = 0;
    while (!workPool.empty())
    {
        int work = workPool.top();
        workPool.pop();
        sum += (work * work);
    }
    
    return sum;
}

int64 solution(int n, vector<int> works) {
    priority_queue<int> workPool;
    for(const auto& work : works)
        workPool.push(work);
    
    while (n != 0)
    {
        int work = workPool.top();
        workPool.pop();
        
        if (work > 0)
            work--;
        workPool.push(work);
        n--;
    }
    
    return SquareSum(workPool);
}