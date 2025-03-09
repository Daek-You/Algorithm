#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); std::cout.tie(NULL); std::cin.tie(NULL);
#define INF 1000000000

void Dijkstra(vector<vector<pair<int, int>>>& adjacentNodes, vector<int>& distances, int start, int V, int E) {
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distances[node] < cost)     // 최단 거리가 아닌 경우, Skip
            continue;

        for (const auto& adjacentNode : adjacentNodes[node]) {
            int next = adjacentNode.first;
            int newDistance = cost + adjacentNode.second;

            // 기존 거리 vs 인접 노드를 거쳐 간 새로운 거리 중 작은 걸 선택
            if (distances[next] > newDistance) {
                distances[next] = newDistance;
                pq.emplace(newDistance, next);
            }
        }
    }
}

int main() {
    FAST_IO
    int V, E, startNode;
    cin >> V >> E >> startNode;

    //  [0] [<2, 5>, <1, 1>]
    //  [1]
    //  [2]
    vector<vector<pair<int, int>>> adjacentNodes(V + 1, vector<pair<int, int>>());  // i번째로부터의 [<연결된 정점 번호, 가중치>]
    int from, to, cost;
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> cost;
        adjacentNodes[from].emplace_back(to, cost);
    }

    vector<int> distances(V + 1, INF);                        // 최소 비용
    Dijkstra(adjacentNodes, distances, startNode, V, E);

    for (int i = 1; i <= V; i++) {
        if (distances[i] == INF)
            cout << "INF" << "\n";
        else
            cout << distances[i] << "\n";
    }

    return 0;
}