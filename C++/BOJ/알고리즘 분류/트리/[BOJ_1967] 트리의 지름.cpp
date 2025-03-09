#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Node = pair<int, int>;    // <노드, 거리>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int FarthestNode, FarthestDistance;

void DFS(const vector<vector<Node>>& graph, vector<bool>& visited, int currentNode, int currentDistance)
{
    if (visited[currentNode])
        return;
    
    if (FarthestDistance < currentDistance)
    {
        FarthestNode = currentNode;
        FarthestDistance = currentDistance;
    }

    visited[currentNode] = true;
    for (const Node& otherNode : graph[currentNode])
    {
        int nextNode = otherNode.first;
        int nextDistance = currentDistance + otherNode.second;
        DFS(graph, visited, nextNode, nextDistance);
    }
}

int main()
{
    FAST_IO
    int N;
    cin >> N;

    // 1. 노드 정보 초기화
    vector<vector<Node>> graph(N + 1, vector<Node>());
    for (int i = 0; i < N - 1; i++)
    {
        int parent, child, distance;
        cin >> parent >> child >> distance;

        graph[parent].emplace_back(Node(child, distance));
        graph[child].emplace_back(Node(parent, distance));
    }

    // 2. 임의의 노드에서 가장 거리가 먼 노드 정보 찾기 (저는 루트부터 시작)
    vector<bool> visited(N + 1, false);
    DFS(graph, visited, 1, 0);

    // 3. 가장 거리가 먼 노드에서 가장 거리가 먼 노드를 찾고, 정답 출력
    std::fill(visited.begin(), visited.end(), false);
    DFS(graph, visited, FarthestNode, 0);

    cout << FarthestDistance;
    return 0;
}