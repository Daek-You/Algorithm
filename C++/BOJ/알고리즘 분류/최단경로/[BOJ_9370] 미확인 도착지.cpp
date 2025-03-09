#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using uint32 = unsigned int;
using Route = pair<uint32, uint32>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 4000000000

void Dijkstra(const vector<vector<Route>>& graph, vector<uint32>& distances, int start)
{
    priority_queue<Route, vector<Route>, greater<Route>> pq;
    
    distances[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        uint32 distance = pq.top().first;
        uint32 destination = pq.top().second;
        pq.pop();

        if (distances[destination] < distance)
            continue;
        
        for (const auto& other : graph[destination])
        {
            uint32 newDistance = distance + other.first;
            uint32 newDestination = other.second;

            if (newDistance < distances[newDestination])
            {
                distances[newDestination] = newDistance;
                pq.emplace(newDistance, newDestination);
            }
        }
    }
}

int main() {
    FAST_IO
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int cityCount, roadCount, destinationCount;
        cin >> cityCount >> roadCount >> destinationCount;

        int start, g, h;
        cin >> start >> g >> h;

        vector<vector<Route>> graph(cityCount + 1, vector<Route>());
        for (int i = 0; i < roadCount; i++)
        {
            int cityA, cityB, distance;
            cin >> cityA >> cityB >> distance;

            graph[cityA].emplace_back(distance, cityB);
            graph[cityB].emplace_back(distance, cityA);
        }

        vector<int> destinations(destinationCount);
        for (int i = 0; i < destinationCount; i++)
            cin >> destinations[i];

        vector<uint32> startToStopover(cityCount + 1, INF);

        Dijkstra(graph, startToStopover, start);
        int startToG = startToStopover[g];
        int startToH = startToStopover[h];
        
        vector<uint32> gToDestination(cityCount + 1, INF);
        Dijkstra(graph, gToDestination, g);

        int gToH = gToDestination[h];

        vector<uint32> htoDestination(cityCount + 1, INF);
        Dijkstra(graph, htoDestination, h);

        vector<int> answers;
        for (const auto& destination : destinations)
        {
            uint32 path1 = startToG + gToH + htoDestination[destination];
            uint32 path2 = startToH + gToH + gToDestination[destination];
            uint32 shortestPath = startToStopover[destination];

            if (shortestPath == path1 or shortestPath == path2)
                answers.push_back(destination);
        }

        sort(answers.begin(), answers.end());
        for (const auto& answer : answers)
            cout << answer << " ";
        cout << "\n";
    }

    return 0;
}