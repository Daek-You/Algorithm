#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000

void Dijkstra(const vector<vector<pair<int, int>>>& nodes, vector<int>& distances, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int nowCost = current.first;
        int nowNode = current.second;

        if (distances[nowNode] < nowCost)
            continue;

        for (const auto& adjacentNode : nodes[nowNode]) {
            int nextNode = adjacentNode.first;
            int nextCost = nowCost + adjacentNode.second;

            if (nextCost < distances[nextNode]) {
                distances[nextNode] = nextCost;
                pq.emplace(nextCost, nextNode);
            }
        }
    }
}

void ResetDistances(vector<int>& distances) {
    for (auto& distance : distances)
        distance = INF;
}

int main() {
    FAST_IO
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adjacentNodes(n + 1, vector<pair<int, int>>());
    int u, v, cost;
    for (int i = 0; i < e; i++){
        cin >> u >> v >> cost;
        adjacentNodes[u].emplace_back(v, cost);
        adjacentNodes[v].emplace_back(u, cost);
    }

    cin >> u >> v;  // 지나야 하는 정점
   
    vector<int> distances(n + 1, INF);
    Dijkstra(adjacentNodes, distances, 1);
    int startToU = distances[u], startToV = distances[v];

    ResetDistances(distances);
    Dijkstra(adjacentNodes, distances, u);
    int uToV = distances[v], uToN = distances[n];

    ResetDistances(distances);
    Dijkstra(adjacentNodes, distances, v);
    int vToN = distances[n];

    int answer = INF;
    int URoute = startToU + uToV + vToN;
    int VRoute = startToV + uToV + uToN;

    answer = min({answer, URoute, VRoute});
    answer = (uToV == INF or answer == INF) ? -1 : answer;
    cout << answer;
    return 0;
}