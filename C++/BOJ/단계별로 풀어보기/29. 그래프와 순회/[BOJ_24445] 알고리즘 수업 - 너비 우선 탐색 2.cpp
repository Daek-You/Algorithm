#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

void BFS(const vector<vector<int>>& edges, vector<int>& orders, int current)
{
	vector<bool> visit(edges.size() + 1, false);
	queue<int> nodes;
	int order = 1;

	nodes.push(current);
	visit[current] = true;
	orders[current] = order++;

	while (!nodes.empty())
	{
		current = nodes.front();
		nodes.pop();

		for (const auto edge : edges[current])
		{
			if (visit[edge])
				continue;

			visit[edge] = true;
			orders[edge] = order++;
			nodes.push(edge);
		}
	}
}

int main()
{
    FAST_IO
    int N, M, R;
    cin >> N >> M >> R;

    // 1. 정점 별 간선 정보 정리
    vector<vector<int>> edges(N + 1, vector<int>());
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);   // 무방향 간선이므로 서로 간선 정보 등록
		edges[v].push_back(u);
    }

    // 2. 정점 별 간선 정보 오름차순 정렬
    for(auto& edge : edges)
        sort(edge.begin(), edge.end(), greater<int>());

	// 3. BFS 탐색 시작
	vector<int> orders(N + 1, 0);
	BFS(edges, orders, R);

	// 4. 결과 출력
	for (int i = 1; i <= N; i++)
		cout << orders[i] << "\n";
    return 0;
}