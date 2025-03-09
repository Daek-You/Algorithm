#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    vector<int> otherNodes;
    int _distance = 0;
};

int BFS(vector<Node>& nodes, const int n, int v)
{
    vector<bool> visited(n + 1, false);
    queue<int> next;
    next.push(v);
    visited[v] = true;

    vector<int> candidates;
    candidates.reserve(n);

    while (!next.empty())
    {
        v = next.front();
        next.pop();

        for (const auto& otherNode : nodes[v].otherNodes)
        {
            if (visited[otherNode])
                continue;

            visited[otherNode] = true;
            int nextDistance = nodes[v]._distance + 1;
            
            nodes[otherNode]._distance = nextDistance;
            candidates.push_back(nextDistance);
            next.push(otherNode);
        }
    }

    sort(candidates.begin(), candidates.end(), greater<int>());
    return std::count(candidates.begin(), candidates.end(), candidates[0]);
}

int solution(int n, vector<vector<int>> edge) {
    // 1. 노드 별로 간선 정보 정리하기
    vector<Node> nodes(n + 1);
    for (const auto& e : edge)
    {
        int start = e[0], dest = e[1];
        nodes[start].otherNodes.emplace_back(dest);
        nodes[dest].otherNodes.emplace_back(start);
    }

    // 2. BFS
    int answer = BFS(nodes, n, 1);
    return answer;
}