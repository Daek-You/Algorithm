#include <vector>
#include <queue>
#include <set>

using namespace std;
using Edge = pair<int, int>;  // <비용, 노드>
#define INF 1000000000

vector<vector<Edge>> Graph;
vector<int> Intensities;
set<int> Summits;

void Initialize(const int n, const vector<vector<int>>& paths, const vector<int>& summits)
{
    Graph.resize(n + 1, vector<Edge>());

    for (const vector<int>& path : paths)
    {
        int from = path[0], to = path[1], cost = path[2];
        Graph[from].emplace_back(Edge(cost, to));
        Graph[to].emplace_back(Edge(cost, from));
    }

    for (const int summit : summits)
        Summits.insert(summit);
}

vector<int> Dijkstra(const int n, const vector<int>& gates)
{
    Intensities.resize(n + 1, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
    vector<int> answer(2, INF);

    for (const int gate : gates)
    {
        edges.emplace(Edge(0, gate));
        Intensities[gate] = 0;
    }

    while (!edges.empty())
    {
        int cost = edges.top().first;
        int currentNode = edges.top().second;
        edges.pop();

        if (Intensities[currentNode] < cost)
            continue;
        
        // 산봉우리에 도착한 경우
        if (Summits.find(currentNode) != Summits.end())
        {
            if (cost < answer[1])
                answer[0] = currentNode, answer[1] = cost;
            else if (cost == answer[1])
                answer[0] = min(answer[0], currentNode);
            continue;
        }

        for (const Edge& edge : Graph[currentNode])
        {
            int weight = edge.first, nextNode = edge.second;
            weight = max(weight, cost);

            if (weight < Intensities[nextNode])
            {
                Intensities[nextNode] = weight;
                edges.emplace(Edge(weight, nextNode));
            }
        } 
    }

    return answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    Initialize(n, paths, summits);
    vector<int> answer = Dijkstra(n, gates);
    return answer;
}