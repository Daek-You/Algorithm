#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Info = pair<int, int>;  // <거리, 노드>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N, M;
vector<vector<Info>> Edges;

void Initialize()
{
    cin >> N >> M;
    Edges.resize(N + 1, vector<Info>());

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, distance;
        cin >> u >> v >> distance;
        Edges[u].push_back(Info(distance, v));
        Edges[v].push_back(Info(distance, u));
    }
}

int BFS(const int sourceNode, const int destinationNode)
{
    queue<Info> nodes;
    vector<bool> visited(N + 1, false);

    nodes.push(Info(0, sourceNode));
    visited[sourceNode] = true;

    while (!nodes.empty())
    {
        int currentDistance = nodes.front().first;
        int currentNode = nodes.front().second;
        nodes.pop();

        if (currentNode == destinationNode)
            return currentDistance;
        
        for (const Info& otherNode : Edges[currentNode])
        {
            int nextDistance = otherNode.first;
            int nextNode = otherNode.second;

            if (visited[nextNode])
                continue;
            
            visited[nextNode] = true;
            nodes.push(Info(currentDistance + nextDistance, nextNode));
        }
    }

    return -1;
}

int main()
{
    FAST_IO
    Initialize();

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        cout << BFS(u, v) << "\n";
    }

    return 0;
}