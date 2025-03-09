#include <iostream>
#include <vector>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N;
vector<vector<int>> Field;
vector<vector<int>> DP;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Initialize()
{
    cin >> N;
    Field.resize(N, vector<int>(N));
    DP.resize(N, vector<int>(N));

    for (int row = 0; row < N; row++)
        for (int column = 0; column < N; column++)
            cin >> Field[row][column];
}

int DFS(int row, int column)
{
    if (DP[row][column] != 0) return DP[row][column];
    DP[row][column] = 1;

    for (const Point& direction : Directions)
    {
        int nextRow = row + direction.first;
        int nextColumn = column + direction.second;

        if (nextRow < 0 or nextRow >= N or nextColumn < 0 or nextColumn >= N or Field[nextRow][nextColumn] <= Field[row][column])
            continue;
        
        DP[row][column] = max(DP[row][column], DFS(nextRow, nextColumn) + 1);
    }

    return DP[row][column];
}

int main()
{
    FAST_IO
    Initialize();
    int answer = 0;

    for (int row = 0; row < N; row++)
        for (int column = 0; column < N; column++)
            answer = max(answer, DFS(row, column));
    
    cout << answer;
    return 0;
}