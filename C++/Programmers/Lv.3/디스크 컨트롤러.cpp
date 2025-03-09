#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Compare
{
    bool operator()(const vector<int>& x, const vector<int>& y) { return x[1] > y[1]; }
};

int solution(vector<vector<int>> jobs)
{
    int N = jobs.size();
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, Compare> readyQueue;
    int answer = 0, i = 0, time = 0;

    while (i < N or !readyQueue.empty())
    {
        if (i < N and jobs[i][0] <= time)
        {
            readyQueue.push(jobs[i++]);
            continue;
        }

        if (!readyQueue.empty())
        {
            time += readyQueue.top()[1];
            answer += time - readyQueue.top()[0];
            readyQueue.pop();
        }

        else
            time = jobs[i][0];
    }

    return answer / N;
}