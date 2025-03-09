#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int rowMoving[4] =    { -1, 1, 0, 0 };
int columnMoving[4] = { 0, 0, -1, 1 };

// BFS
int ExploreSurroundingLand(const vector<string>& maps, vector<vector<bool>>& visited, pair<int, int> currentPosition)
{
	if (visited[currentPosition.first][currentPosition.second] or maps[currentPosition.first][currentPosition.second] == 'X')
		return 0;

	int sumOfFood = maps[currentPosition.first][currentPosition.second] - '0';
	queue<pair<int, int>> positions;
	positions.push(currentPosition);
	visited[currentPosition.first][currentPosition.second] = true;

	while (!positions.empty())
	{
		auto current = positions.front();
		int row = current.first;
		int col = current.second;
		positions.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextRow = row + rowMoving[i];
			int nextColumn = col + columnMoving[i];

			if (nextRow < 0 or nextRow >= maps.size() or nextColumn < 0 or nextColumn >= maps[0].length())
				continue;
			if (visited[nextRow][nextColumn] or maps[nextRow][nextColumn] == 'X')
				continue;
			
			positions.push(make_pair(nextRow, nextColumn));
			visited[nextRow][nextColumn] = true;
			sumOfFood += maps[nextRow][nextColumn] - '0';
		}
	}

	return sumOfFood;
}

vector<int> GetUninhabitedIslandDays(const vector<string>& maps)
{
	vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
	vector<int> days;

	for (int row = 0; row < maps.size(); row++)
	{
		for (int col = 0; col < maps[0].length(); col++)
		{
			int totalDays = ExploreSurroundingLand(maps, visited, make_pair(row, col));

			if (totalDays != 0)
				days.push_back(totalDays);
		}
	}

	sort(days.begin(), days.end());
	return days;
}


vector<int> solution(vector<string> maps) {
	vector<int> answer = GetUninhabitedIslandDays(maps);

	if (answer.empty())
		answer.push_back(-1);
	return answer;
}