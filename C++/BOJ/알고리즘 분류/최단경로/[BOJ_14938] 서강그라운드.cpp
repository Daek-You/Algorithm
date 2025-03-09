#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Road = pair<int, int>;  // <길의 길이, 목적지 번호>

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000

int RegionNums, DetectingRange, RoadNums;

int Solution(const vector<vector<Road>>& graph, const vector<int>& items, int start)
{
    priority_queue<Road, vector<Road>, greater<Road>> next;
    vector<int> distances(RegionNums + 1, INF);

    distances[start] = 0;
    next.emplace(0, start);

    while (!next.empty())
    {
        Road road = next.top();
        int roadLength = road.first;
        int destination = road.second;
        next.pop();

        if (distances[destination] < roadLength)
            continue;
        
        for (const Road& other : graph[destination])
        {
            int newLength = other.first + roadLength;
            int newRegion = other.second;

            if (newLength < distances[newRegion])
            {
                distances[newRegion] = newLength;
                next.emplace(newLength, newRegion);
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= RegionNums; i++)
    {
        if (DetectingRange < distances[i])
            continue;
        sum += items[i];
    }
    
    return sum;
}

int main()
{
    FAST_IO
    cin >> RegionNums >> DetectingRange >> RoadNums;

    vector<int> itemCounts(RegionNums + 1);

    for (int i = 1; i <= RegionNums; i++)
        cin >> itemCounts[i];

    int regionA, regionB, roadLength;
    vector<vector<Road>> graph(RegionNums + 1, vector<Road>());

    for (int i = 0; i < RoadNums; i++)
    {
        cin >> regionA >> regionB >> roadLength;
        graph[regionA].emplace_back(roadLength, regionB);
        graph[regionB].emplace_back(roadLength, regionA);
    }

    int answer = 0;
    for (int i = 1; i <= RegionNums; i++)
        answer = max(answer, Solution(graph, itemCounts, i));

    cout << answer;
    return 0;
}