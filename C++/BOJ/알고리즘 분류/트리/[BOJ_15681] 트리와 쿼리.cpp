#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int NumOfVertexes, RootNumber, NumOfQueries;
vector<vector<int>> Edges;
vector<int> Children;
vector<bool> Visited;

void Initialize()
{
    cin >> NumOfVertexes >> RootNumber >> NumOfQueries;
    Edges.resize(NumOfVertexes + 1, vector<int>());
    Children.resize(NumOfVertexes + 1, 0);
    Visited.resize(NumOfVertexes + 1, false);

    for (int i = 0; i < NumOfVertexes - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }
}

int DFS(int node)
{
    if (Children[node] != 0)
        return Children[node];
    
    Visited[node] = true;
    int vertexCount = 1;

    for (const int nextNode : Edges[node])
    {
        if (Visited[nextNode])
            continue;
        vertexCount += DFS(nextNode);
    }

    Children[node] = vertexCount;
    return vertexCount;
}

int main()
{
    FAST_IO
    Initialize();
    Children[RootNumber] = DFS(RootNumber);

    while (NumOfQueries--)
    {
        int node;
        cin >> node;
        cout << Children[node] << "\n";
    }

    return 0;
}