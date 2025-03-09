#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define UNVISITED -1
#define EMPTY 0
#define WALL  1
#define VIRUS 2
#define INF 1000000000

int N, M, NumOfEmpties = 0;
vector<vector<int>> Field;
vector<Point> VirusPositions;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Initialize()
{
    cin >> N >> M;
    Field.resize(N, vector<int>(N));

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cin >> Field[r][c];

            if (Field[r][c] == EMPTY) NumOfEmpties++;
            else if (Field[r][c] == VIRUS) VirusPositions.push_back(Point(r, c));
        }
    }
}

void StartSimulation(const vector<Point>& viruses, int& answer)
{
    queue<Point> positions;
    vector<vector<int>> times(N, vector<int>(N, UNVISITED));

    for (Point virus : viruses)
    {
        positions.push(virus);
        times[virus.first][virus.second] = 0;
    }

    int numOfEmptyInfected = 0, totalTime = 0;

    while (!positions.empty())
    {
        int row = positions.front().first;
        int column = positions.front().second;
        positions.pop();

        for (const Point& direction : Directions)
        {
            int nextRow = row + direction.first;
            int nextColumn = column + direction.second;

            if (nextRow < 0 or nextRow >= N or nextColumn < 0 or nextColumn >= N)
                continue;
            
            if (Field[nextRow][nextColumn] == WALL or times[nextRow][nextColumn] != UNVISITED)
                continue;
            
            times[nextRow][nextColumn] = times[row][column] + 1;
            positions.push(Point(nextRow, nextColumn));

            if (Field[nextRow][nextColumn] == EMPTY)
            {
                numOfEmptyInfected++;
                totalTime = times[nextRow][nextColumn];
            }
        }
    }

    if (NumOfEmpties == numOfEmptyInfected)
        answer = min(answer, totalTime);
}

void FindVirusCombinationsToActivate(vector<Point>& viruses, int idx, int& answer)
{
    if (viruses.size() == M)
    {
        StartSimulation(viruses, answer);
        return;
    }

    for (int i = idx; i < VirusPositions.size(); i++)
    {
        viruses.push_back(VirusPositions[i]);
        FindVirusCombinationsToActivate(viruses, i + 1, answer);
        viruses.pop_back();
    }
}

int main()
{
    FAST_IO
    int answer = INF;
    vector<Point> viruses;

    Initialize();
    FindVirusCombinationsToActivate(viruses, 0, answer);
    
    if (answer == INF) cout << "-1";
    else cout << answer;
    return 0;
}