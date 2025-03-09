#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    if (x == y)
        return 0;
    
    vector<int> operationCounts(y + 1, 0);
    queue<int> myQueue;
    myQueue.push(x);

    while(!myQueue.empty())
    {
        vector<int> results(3);
        int num = myQueue.front();
        myQueue.pop();
        
        results[0] = num + n;
        results[1] = num * 2;
        results[2] = num * 3;
        
        for(int i = 0; i < 3; i++)
        {
            if(results[i] > y)
                continue;
            
            int targetIdx = results[i];
            int preCount = operationCounts[num];
            int count = operationCounts[targetIdx];
            
            if(count == 0 or count > preCount + 1)
            {
                operationCounts[targetIdx] = preCount + 1;
                myQueue.push(results[i]);
            }
        }
    }

    return operationCounts[y] != 0 ? operationCounts[y] : -1;
}