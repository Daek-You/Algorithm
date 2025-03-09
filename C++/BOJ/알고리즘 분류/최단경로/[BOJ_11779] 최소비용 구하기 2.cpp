#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using uint32 = unsigned int;
using Info = pair<uint32, uint32>;    // <비용, 목적지>

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 3000000000

vector<uint32> Costs;

stack<int> Dijkstra(const vector<vector<Info>>& routes, const uint32 N, uint32 startCity, uint32 destinationCity) {
    vector<uint32> traces(N + 1);
    priority_queue<Info, vector<Info>, greater<Info>> pq;

    Costs[startCity] = 0;
    pq.emplace(0, startCity);

    while (!pq.empty()) {
        uint32 cost = pq.top().first;
        uint32 city = pq.top().second;
        pq.pop();

        if (Costs[city] < cost)
            continue;
        
        for (const auto& adjacentCity : routes[city]) {
            uint32 nextCost = cost + adjacentCity.first;
            uint32 nextCity = adjacentCity.second;

            if (nextCost < Costs[nextCity]) {
                Costs[nextCity] = nextCost;
                traces[nextCity] = city;
                pq.emplace(nextCost, nextCity);
            }
        }
    }

    stack<int> answers;
    uint32 city = destinationCity;
    answers.push(city);

    while (traces[city] != 0) {
        answers.push(traces[city]);
        city = traces[city];
    }

    return answers;
}

int main() {
    FAST_IO
    uint32 n, m, from, to, cost;
    cin >> n >> m;

    vector<vector<Info>> busRoutes(n + 1, vector<Info>());
    Costs.resize(n + 1, MAX);

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        busRoutes[from].emplace_back(cost, to);
    }

    uint32 startCity, destinationCity;
    cin >> startCity >> destinationCity;

    stack<int> routes = Dijkstra(busRoutes, n, startCity, destinationCity);
    
    cout << Costs[destinationCity] << "\n";
    cout << routes.size() << "\n";

    while (!routes.empty()) {
        cout << routes.top() << " ";
        routes.pop();
    }

    return 0;
}