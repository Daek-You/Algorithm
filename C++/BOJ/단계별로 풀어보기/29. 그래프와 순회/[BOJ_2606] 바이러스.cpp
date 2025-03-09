#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int FindComputersWithVirus(const vector<vector<int>>& edges, int startComputerNumber)
{
	int virusComputers = 0;
	vector<bool> visit(edges.size() + 1, false);
	queue<int> nodes;

	nodes.push(startComputerNumber);
	visit[startComputerNumber] = true;

	while (!nodes.empty())
	{
		int currentComputer = nodes.front();
		nodes.pop();

		for (const auto& nextComputer : edges[currentComputer])
		{
			if (visit[nextComputer])
				continue;
			visit[nextComputer] = true;
			virusComputers++;
			nodes.push(nextComputer);
		}
	}

	return virusComputers;
}

int main()
{
    FAST_IO
    int computerNums, edgeNums;
	cin >> computerNums >> edgeNums;

	vector<vector<int>> edges(computerNums + 1, vector<int>());
	for (int i = 0; i < edgeNums; i++)
	{
		int from, to;
		cin >> from >> to;

		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	int answer = FindComputersWithVirus(edges, 1);
	cout << answer;
    return 0;
}