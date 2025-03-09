#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void BFS(const vector<vector<int>>& nodes, int numOfNodes, int rootNode)
{
    vector<bool> visited(numOfNodes + 1, false);
    vector<int> answer(numOfNodes + 1);
    queue<int> nodequeue;

    visited[rootNode] = true;
    nodequeue.push(rootNode);

    while (!nodequeue.empty())
    {
        int currentNode = nodequeue.front();
        nodequeue.pop();

        for (const int& childNode : nodes[currentNode])
        {
            if (visited[childNode])
                continue;
            answer[childNode] = currentNode;
            visited[childNode] = true;
            nodequeue.push(childNode);
        }
    }

    for (int i = 2; i <= numOfNodes; i++)
        cout << answer[i] << "\n";
}

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<vector<int>> nodes(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> from >> to;
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }

    BFS(nodes, N, 1);
    return 0;
}