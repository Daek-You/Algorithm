#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using uint32 = unsigned int;
using Route = pair<uint32, uint32>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 4000000000

void Dijkstra(const vector<vector<Route>>& routes, vector<uint32>& distances, uint32 start) {
    priority_queue<Route, vector<Route>, greater<Route>> buses;
    distances[start] = 0;
    buses.emplace(0, start);

    while (!buses.empty()) {
        Route bus = buses.top();
        uint32 nextCityCost = bus.first;
        uint32 nextCity = bus.second;
        buses.pop();

        if (distances[nextCity] < nextCityCost)
            continue;

        for (const auto& route : routes[nextCity]) {
            uint32 newCityCost = route.first;
            uint32 newCity = route.second;
            uint32 newPathCost = distances[nextCity] + newCityCost;

            if (newPathCost < distances[newCity]) {
                distances[newCity] = newPathCost ;
                buses.emplace(newPathCost, newCity);
            }
        }
    }
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    uint32 from, to, cost;
    vector<vector<Route>> busRouteInfo(N + 1, vector<Route>());
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> cost;
        busRouteInfo[from].emplace_back(cost, to);
    }

    vector<uint32> distances(N + 1, INF);
    uint32 start, destination;
    cin >> start >> destination;

    Dijkstra(busRouteInfo, distances, start);
    cout << distances[destination];

    return 0;
}