#include <vector>
using namespace std;
using uint32 = unsigned int;
#define INF 3000000000

void FloydWarshall(vector<vector<uint32>>& graph, int n)
{
    for (int mid = 1; mid <= n; mid++)
        for (int from = 1; from <= n; from++)
            for (int to = 1; to <= n; to++)
                graph[from][to] = min(graph[from][to], graph[from][mid] + graph[mid][to]);
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    // 1. Input Initialize
    vector<vector<uint32>> graph(n + 1, vector<uint32>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for (const vector<int>& fare : fares)
    {
        uint32 from = fare[0], to = fare[1], cost = fare[2];
        graph[from][to] = graph[to][from] = cost;
    }

    // 2. Floyd-Warshall Algorithm
    FloydWarshall(graph, n);
    uint32 answer = INF;

    for (int i = 1; i <= n; i++)
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    return answer;
}