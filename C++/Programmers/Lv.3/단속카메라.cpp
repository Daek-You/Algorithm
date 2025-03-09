#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](const vector<int>& r1, const vector<int>& r2) { return r1[1] < r2[1]; });

    int standardLine = routes[0][1];
    int answer = 1;
    
    for (int i = 1; i < routes.size(); i++)
    {
        int enter = routes[i][0], exit = routes[i][1];
        
        if (enter <= standardLine)
            continue;
        answer++;
        standardLine = exit;
    }
    
    return answer;
}

/*    ------          ---
    -----    ----------  
  -20  -15 -14       -5 -3      

    -> 진출 시점을 기준으로 정렬하여 비교하면 되겠다.
*/