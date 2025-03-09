#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int TopologicalSort(const vector<vector<int>>& edges, vector<int>& inDegrees, vector<int>& order, int M)
{
    queue<int> nodes;
    for (int i = 1; i <= M; i++)
    {
        if (inDegrees[i] == 0)
        {
            nodes.push(i);
            order[i] = 1;
        }
    }

    vector<vector<int>> inDegreeOrders(M + 1, vector<int>());
    for (int i = 1; i <= M; i++)
    {
        int currentNode = nodes.front();
        nodes.pop();

        for (const int& otherNode : edges[currentNode])
        {
            --inDegrees[otherNode];
            inDegreeOrders[otherNode].emplace_back(order[currentNode]);

            if (inDegrees[otherNode] == 0)
            {
                int maxStrahler = *max_element(inDegreeOrders[otherNode].begin(), inDegreeOrders[otherNode].end());
                int count = std::count(inDegreeOrders[otherNode].begin(), inDegreeOrders[otherNode].end(), maxStrahler);
                int value = (count > 1) ? maxStrahler + 1 : maxStrahler;

                order[otherNode] = value;
                nodes.push(otherNode);
            }
        }
    }

    return *max_element(order.begin(), order.end());    
}

int main()
{
    FAST_IO
    int testCaseCount, testCastNumber, M, P;
    cin >> testCaseCount;

    while (testCaseCount--)
    {
        cin >> testCastNumber >> M >> P;

        vector<int> order(M + 1);
        vector<int> inDegrees(M + 1);
        vector<vector<int>> edges(M + 1, vector<int>());
        int from, to;

        for (int i = 0; i < P; i++)
        {
            cin >> from >> to;
            edges[from].emplace_back(to);
            inDegrees[to]++;
        }

        int answer = TopologicalSort(edges, inDegrees, order, M);
        cout << testCastNumber << " " << answer << "\n";
    }

    return 0;
}