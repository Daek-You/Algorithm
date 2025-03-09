#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    long long left = static_cast<long long>(times.front());
    long long right = static_cast<long long>(times.back()) * static_cast<long long>(n);
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (const int time : times)
            count += (mid / time);
        
        if (n <= count)
        {
            right = mid - 1;
            answer = mid;
        }
        else
            left = mid + 1;
    }
    
    return answer;
}