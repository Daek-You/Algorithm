#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Node = pair<int, int>;  // <노드, 거리>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int FarthestNode, FarthestDistance;

void DFS(const vector<vector<Node>>& nodes, vector<bool>& visited, int V, int radius)
{
    if (visited[V])
        return;
    
    if (FarthestDistance < radius)
    {
        FarthestNode = V;
        FarthestDistance = radius;
    }

    visited[V] = true;
    for (const Node& otherNode : nodes[V])
    {
        int nodeID = otherNode.first;
        int distance = otherNode.second;
        DFS(nodes, visited, nodeID, radius + distance);
    }
}

int main()
{
    FAST_IO
    int V;
    cin >> V;

    vector<vector<Node>> nodes(V + 1, vector<Node>());
    vector<bool> visited(V + 1, false);
    int from, to, distance;

    while (V--)
    {
        cin >> from;

        while (true)
        {
            cin >> to;
            if (to == -1) break;

            cin >> distance;
            nodes[from].emplace_back(Node(to, distance));
            nodes[to].emplace_back(Node(from, distance));
        }
    }

    DFS(nodes, visited, 1, 0);
    std::fill(visited.begin(), visited.end(), false);
    DFS(nodes, visited, FarthestNode, 0);

    cout << FarthestDistance;
    return 0;
}