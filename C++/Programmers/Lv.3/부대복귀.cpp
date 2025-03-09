#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;
using Data = pair<int, int>;    // <비용, 지역>

void Dijkstra(const vector<vector<int>>& routes, vector<int>& distances, int n, int source) {
    queue<Data> regions;
    distances[source] = 0;
    regions.emplace(0, source);
    
    while (!regions.empty()) {
        int cost = regions.front().first;
        int region = regions.front().second;
        regions.pop();
        
        if (cost < distances[region])
            continue;
        
        for (const int& nextRegion : routes[region]) {
            int nextCost = cost + 1;
            if (nextCost < distances[nextRegion]) {
                distances[nextRegion] = nextCost;
                regions.emplace(nextCost, nextRegion);
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> routes(n + 1, vector<int>());
    for (const vector<int>& road : roads) {
        int from = road[0], to = road[1];
        routes[from].emplace_back(to);
        routes[to].emplace_back(from);
    }

    vector<int> answer;
    vector<int> distances(n + 1, INF);

    Dijkstra(routes, distances, n, destination);
    for (const auto& source : sources) {
        int distance = distances[source] == INF ? -1 : distances[source];
        answer.emplace_back(distance);        
    }
    
    return answer;
}