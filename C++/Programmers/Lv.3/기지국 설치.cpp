#include <vector>
using namespace std;

bool IsInRange(int targetStation, int myStation, int range)
{
    return targetStation - range <= myStation and myStation <= targetStation + range;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int currentStation = 1;
    int idx = 0;

    while (currentStation <= n)
    {
        if (idx < stations.size() and IsInRange(stations[idx], currentStation, w))
        {
            currentStation = stations[idx] + w;
            idx++;
        }
        else
        {
            currentStation += w * 2;
            answer++;
        }
        
        currentStation++;
    }

    return answer;
}