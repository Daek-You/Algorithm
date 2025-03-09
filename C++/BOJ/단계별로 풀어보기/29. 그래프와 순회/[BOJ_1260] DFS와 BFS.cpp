#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

void DFS(const vector<vector<int>>& edges, vector<int>& answers, vector<bool>& visit, int V)
{
	visit[V] = true;
	answers.emplace_back(V);

	for (const auto& next : edges[V])
	{
		if (visit[next])
			continue;
		DFS(edges, answers, visit, next);
	}
}

void BFS(const vector<vector<int>>& edges, vector<int>& answers, vector<bool>& visit, int V)
{
	queue<int> nodes;
	nodes.push(V);
	answers.emplace_back(V);
	visit[V] = true;

	while (!nodes.empty())
	{
		int current = nodes.front();
		nodes.pop();

		for (const auto next : edges[current])
		{
			if (visit[next])
				continue;
			visit[next] = true;
			answers.emplace_back(next);
			nodes.push(next);
		}
	}
}

void Print(const vector<int>& answers)
{
	for (const auto& answer : answers)
		cout << answer << " ";
	cout << "\n";
}

int main()
{
    FAST_IO
    int N, M, V;
	cin >> N >> M >> V;

	// 1. 정점에 대한 간선 정보 정리
	vector<vector<int>> edges(N + 1, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;

		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	// 2. 오름차순 정렬
	for (auto& edge : edges)
		sort(edge.begin(), edge.end());
	
	vector<int> answers;
	vector<bool> visit(N + 1, false);
	
	DFS(edges, answers, visit, V);
	Print(answers);

	answers.clear();
	std::fill(visit.begin(), visit.end(), false);
	BFS(edges, answers, visit, V);
	Print(answers);

    return 0;
}