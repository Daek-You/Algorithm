#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Data = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000
#define STEP_COUNT 3
#define MAX_DISTANCE 100000

int GetNextPosition(int position, int step)
{
    switch(step)
    {
        case 0: return position - 1;
        case 1: return position + 1;
        case 2: return position * 2;
    }

    return 0;
}

Data Dijkstra(int start, int destination)
{
    vector<int> times(MAX_DISTANCE + 1, INF);
    priority_queue<Data, vector<Data>, greater<Data>> next;   // <시간, 위치>
    int caseCount = 0;

    times[start] = 0;
    next.emplace(Data(0, start));

    while (!next.empty())
    {
        int currentTime = next.top().first;
        int currentPosition = next.top().second;
        next.pop();

        times[currentPosition] = min(times[currentPosition], currentTime);  // 더 작은 값으로 시간 갱신
        if (currentPosition == destination and currentTime == times[currentPosition])  // 시간 가중치는 1이기 때문에 먼저 도착한 경로가 최단 경로
            caseCount++;

        if (times[currentPosition] < currentTime)   // 더 빠른 경로가 기존에 있을 경우
            continue;

        if (times[destination] < currentTime)       // 큐에 남아 있는 최단 경로보다 더 짧은 경로가 있을 경우 탐색 진행 X
            break;
        
        for (int step = 0; step < STEP_COUNT; step++)
        {
            int nextPosition = GetNextPosition(currentPosition, step);
            int nextTime = times[currentPosition] + 1;

            if (nextPosition < 0 or nextPosition > MAX_DISTANCE)
                continue;
            next.emplace(Data(nextTime, nextPosition));
        }
    }

    return make_pair(times[destination], caseCount);
}

int main()
{
    FAST_IO
    int subinPosition, sisterPosition;
    cin >> subinPosition >> sisterPosition;

    Data answer = Dijkstra(subinPosition, sisterPosition);
    cout << answer.first << "\n" << answer.second;
    return 0;
}