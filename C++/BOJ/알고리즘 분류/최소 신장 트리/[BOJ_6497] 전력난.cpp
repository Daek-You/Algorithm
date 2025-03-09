#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Edge = pair<int, int>;  // <거리, 집>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int Prim(const vector<vector<Edge>>& graph, int start)
{
    vector<bool> MST(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

    int minDistance = 0;
    MST[start] = true;

    // 시작 집과 연결된 모든 길 등록
    for (const Edge& edge : graph[start])
        edges.emplace(edge);

    while (!edges.empty())
    {
        int distance = edges.top().first;
        int house = edges.top().second;
        edges.pop();

        if (MST[house])
            continue;

        MST[house] = true;
        minDistance += distance;

        for (const Edge& edge : graph[house])
        {
            int nextDistance = edge.first;
            int nextHouse = edge.second;

            if (MST[nextHouse])
                continue;
            edges.emplace(Edge(nextDistance, nextHouse));
        }
    }

    return minDistance;
}

int main()
{
    FAST_IO

    while (true)
    {
        int M, N;
        cin >> M >> N;

        if (M == 0 and N == 0)
            break;
        
        // 1. 그래프 간선 정보 형성
        vector<vector<Edge>> graph(M, vector<Edge>());
        int from, to, distance, originalCost = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> from >> to >> distance;
            graph[from].emplace_back(Edge(distance, to));
            graph[to].emplace_back(Edge(distance, from));
            originalCost += distance;
        }

        int answer = Prim(graph, 0);
        cout << originalCost - answer << "\n";
    }

    return 0;
}