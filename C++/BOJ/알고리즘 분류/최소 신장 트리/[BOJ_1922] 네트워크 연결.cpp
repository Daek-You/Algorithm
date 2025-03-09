#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using Data = pair<int, int>;    // <비용, 다른 컴퓨터>

int MinimumSpanningTree(const vector<vector<Data>>& graph, int startVertex) {
    // 1. 시작 정점 방문 처리
    vector<bool> visit(graph.size(), false);
    visit[startVertex] = true;

    priority_queue<Data, vector<Data>, greater<Data>> candidateVertexes;

    // 2. 시작 정점과 인접한 다른 정점 정보 우선순위 큐에 넣기
    for (const auto& adjacentVertex : graph[startVertex]) {
        int cost = adjacentVertex.first;
        int next = adjacentVertex.second;
        candidateVertexes.emplace(cost, next);
    }

    int answer = 0;

    while (!candidateVertexes.empty()) {
        int nextCost = candidateVertexes.top().first;
        int nextVertex = candidateVertexes.top().second;
        candidateVertexes.pop();

        if (visit[nextVertex])
            continue;

        // 3. 방문하지 않은 인접 정점들 중에 가장 낮은 가중치를 가진 정점 방문        
        visit[nextVertex] = true;
        answer += nextCost;

        // 4. 방금 방문한 정점과 인접한 정점 정보 우선 순위 큐에 넣기
        for (const auto& adjacentVertex : graph[nextVertex]) {
            int candidateCost = adjacentVertex.first;
            int candidateVertex = adjacentVertex.second;
            candidateVertexes.emplace(candidateCost, candidateVertex);
        }
    }

    return answer;
}

int main() {
    FAST_IO
    int computerCount, connectableDataCount;
    cin >> computerCount >> connectableDataCount;

    vector<vector<Data>> adjacentComputers(computerCount + 1, vector<Data>());
    int nodeA, nodeB, cost;
    
    for (int i = 0; i < connectableDataCount; i++) {
        cin >> nodeA >> nodeB >> cost;
        adjacentComputers[nodeA].emplace_back(cost, nodeB);
        adjacentComputers[nodeB].emplace_back(cost, nodeA);
    }

    int answer = MinimumSpanningTree(adjacentComputers, computerCount);
    cout << answer;
    return 0;
}