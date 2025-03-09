#include <vector>
#include <algorithm>
using namespace std;
using int64 = long long;

int64 OperationCount;
vector<vector<int>> Edges;
vector<bool> Visited;

void Initialize(const vector<int>& a, const vector<vector<int>>& edges)
{
    OperationCount = 0;
    Edges.resize(a.size());
    Visited.resize(a.size(), false);

    for (const vector<int>& edge : edges)
    {
        int from = edge[0], to = edge[1];
        Edges[from].push_back(to);
        Edges[to].push_back(from);
    }
}

int64 DFS(vector<int>& weights, int node)
{
    Visited[node] = true;
    int64 weight = weights[node];

    for (const int childNode : Edges[node])
    {
        if (Visited[childNode]) continue;
        weight += DFS(weights, childNode);
    }

    OperationCount += abs(weight);
    return weight; 
}

int64 solution(vector<int> a, vector<vector<int>> edges)
{
    Initialize(a, edges);

    if (DFS(a, 0) != 0)
        return -1;
    return OperationCount;
}