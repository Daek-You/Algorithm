#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
using Position = pair<int, int>;    // <행, 열>

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define WATER       'W'
#define LAND        'L'
#define UNVISITED   -1

int MaxRow, MaxColumn;
vector<Position> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int BFS(const vector<string>& map, int row, int col)
{
    vector<vector<int>> distances(MaxRow, vector<int>(MaxColumn, UNVISITED));
    queue<Position> landPositions;
    int maxDistance = 0;

    landPositions.emplace(Position(row, col));
    distances[row][col] = 0;

    while (!landPositions.empty())
    {
        row = landPositions.front().first;
        col = landPositions.front().second;
        landPositions.pop();

        for (const Position& direction : Directions)
        {
            int nextRow = row + direction.first;
            int nextCol = col + direction.second;

            if (nextRow < 0 or nextRow >= MaxRow or nextCol < 0 or nextCol >= MaxColumn)
                continue;
            if (map[nextRow][nextCol] == WATER or distances[nextRow][nextCol] != UNVISITED)
                continue;

            distances[nextRow][nextCol] = distances[row][col] + 1;
            landPositions.emplace(Position(nextRow, nextCol));
            maxDistance = max(maxDistance, distances[nextRow][nextCol]);
        }
    }

    return maxDistance;
}

int main()
{
    FAST_IO
    cin >> MaxRow >> MaxColumn;

    vector<string> map(MaxRow);
    for (int row = 0; row < MaxRow; row++)
        cin >> map[row];

    int answer = 0;
    for (int row = 0; row < MaxRow; row++)
        for (int col = 0; col < MaxColumn; col++)
            if (map[row][col] != WATER)
                answer = max(answer, BFS(map, row, col));

    cout << answer;
    return 0;
}