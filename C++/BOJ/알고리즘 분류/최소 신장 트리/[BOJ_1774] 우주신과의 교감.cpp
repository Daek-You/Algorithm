#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using Position = pair<long, long>;
using Edge = pair<double, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

double GetDistance(const pair<long, long>& pos1, const pair<long, long>& pos2)
{
    double deltaX = pow(pos1.first - pos2.first, 2);
    double deltaY = pow(pos1.second - pos2.second, 2);
    return sqrt(deltaX + deltaY);
}

double Prim(const vector<vector<double>>& distances, int N)
{
    vector<bool> visited(N + 1, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    double cost = 0;

    visited[1] = true;
    for (int i = 2; i <= N; i++)
        pq.emplace(Edge(distances[1][i], i));
    
    while (!pq.empty())
    {
        double currentCost = pq.top().first;
        int currentId = pq.top().second;
        pq.pop();

        if (visited[currentId])
            continue;
        
        visited[currentId] = true;
        cost += currentCost;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i])
                continue;
            pq.emplace(Edge(distances[currentId][i], i));
        }
    }

    return cost;
}

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    // 1. 우주신들 위치값 저장
    vector<Position> positions(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> positions[i].first >> positions[i].second;

    // 2. 우주신들 및 황선자씨와의 거리 계산
    vector<vector<double>> distances(N + 1, vector<double>(N + 1));
    for (int from = 1; from <= N; from++)
        for (int to = from + 1; to <= N; to++)
            distances[from][to] = distances[to][from] = GetDistance(positions[from], positions[to]);

    // 3. 이미 등록된 간선 정보 처리
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        distances[from][to] = distances[to][from] = 0;
    }

    // 4. 프림의 알고리즘
    double answer = Prim(distances, N);
    cout << fixed;
    cout.precision(2);
    cout << answer;
    return 0;
}