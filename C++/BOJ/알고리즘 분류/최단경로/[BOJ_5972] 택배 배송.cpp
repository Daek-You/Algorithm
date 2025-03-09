#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Route = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 10e9

int N, M;
vector<vector<Route>> Routes;

void Initialize()
{
    cin >> N >> M;
    Routes.resize(N + 1, vector<Route>());

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        Routes[from].push_back({cost, to});
        Routes[to].push_back({cost, from});
    }
}

int Dijkstra(const int source, const int destination)
{
    vector<int> costs(N + 1, INF);
    priority_queue<Route, vector<Route>, greater<Route>> pq;

    pq.push({0, source});
    costs[source] = 0;

    while (!pq.empty())
    {
        Route current = pq.top();
        int currentCost = current.first;
        int currentNode = current.second;
        pq.pop();

        if (costs[currentNode] < currentCost)
            continue;

        for (const Route& otherRoute : Routes[currentNode])
        {
            int nextCost = otherRoute.first;
            int nextNode = otherRoute.second;

            if (currentCost + nextCost < costs[nextNode])
            {
                costs[nextNode] = currentCost + nextCost;
                pq.push({currentCost + nextCost, nextNode});
            }
        }
    }

    return costs[N];
}

int main()
{
    FAST_IO
    Initialize();

    int answer = Dijkstra(1, N);
    cout << answer;
    return 0;
}
