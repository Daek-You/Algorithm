#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using Data = pair<int, int>;    // <비용, 정점>

int Prim(const vector<vector<Data>>& graph, int start) {
    vector<bool> MST(graph.size(), false);
    MST[start] = true;

    priority_queue<Data, vector<Data>, greater<Data>> adjacentVertexes;
    for (const auto& adjacentVertex : graph[start]) {
        int cost = adjacentVertex.first;
        int vertex = adjacentVertex.second;
        adjacentVertexes.emplace(cost, vertex);
    }

    int weight = 0;

    while (!adjacentVertexes.empty()) {
        int nextCost = adjacentVertexes.top().first;
        int nextVertex = adjacentVertexes.top().second;
        adjacentVertexes.pop();

        if (MST[nextVertex])
            continue;
        
        MST[nextVertex] = true;
        weight += nextCost;

        for (const auto& adjacentVertex : graph[nextVertex]) {
            int cost = adjacentVertex.first;
            int vertex = adjacentVertex.second;
            adjacentVertexes.emplace(cost, vertex);
        }
    }

    return weight;
}

int main() {
    FAST_IO
    int V, E;
    cin >> V >> E;

    vector<vector<Data>> graph(V + 1, vector<Data>());
    int u, v, cost;
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> cost;
        graph[u].emplace_back(cost, v);
        graph[v].emplace_back(cost, u);
    }

    int answer = Prim(graph, 1);
    cout << answer;
    return 0;
}