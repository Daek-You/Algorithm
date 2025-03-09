#include <vector>
#include <queue>
using namespace std;
using Point = pair<int, int>;
#define EMPTY   0
#define WALL    1
#define STRAIGHT_COST   100
#define CORNER_COST     600
#define INF     1000000000

int N;
vector<vector<int>> Board;
vector<vector<vector<vector<int>>>> DP;
vector<Point> Directions { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 상, 우, 하, 좌
const int ZeroDirectionIndex = -1;

struct Road
{
    Road() { }
    Road(int r, int c, int di, int cost) : row(r), column(c), directionIndex(di), cost(cost) { }
    int row, column;
    int directionIndex, cost;
};

int BFS(int row, int column)
{
    queue<Road> roads;
    roads.push(Road(row, column, ZeroDirectionIndex, 0));
    DP[0][0][0][0] = 0;

    while (!roads.empty())
    {
        Road current = roads.front();
        int additionalCost = STRAIGHT_COST;
        roads.pop();

        for (int i = 0; i < Directions.size(); i++)
        {
            row = current.row, column = current.column;
            int nextRow = current.row + Directions[i].first;
            int nextColumn = current.column + Directions[i].second;

            // 보드 밖 or 벽일 경우
            if (nextRow < 0 or nextRow >= N or nextColumn < 0 or nextColumn >= N or Board[nextRow][nextColumn] == WALL)
                continue;

            // 진행하던 방향의 역방향으로 가는 경로일 경우 (ex. 오른쪽으로 왔는데, 다시 왼쪽으로 갈 필요 X)
            if (current.directionIndex != ZeroDirectionIndex and i == ((current.directionIndex + 2) % Directions.size()))
                continue;

            if (current.directionIndex != ZeroDirectionIndex)
                additionalCost = (i == current.directionIndex) ? STRAIGHT_COST : CORNER_COST;

            int newCost = current.cost + additionalCost;

            // 이미 방문한 적이 있는 경로를 더 비싼 값 주고 가야 하는 경우
            if (DP[row][column][nextRow][nextColumn] <= newCost)
                continue;

            DP[row][column][nextRow][nextColumn] = newCost;
            roads.push(Road(nextRow, nextColumn, i, newCost));
        }
    }

    int leftPathCost = DP[N - 1][N - 2][N - 1][N - 1];
    int downPathCost = DP[N - 2][N - 1][N - 1][N - 1];
    return min(leftPathCost, downPathCost);
}

int solution(vector<vector<int>> board)
{
    N = board.size();
    Board = board;
    DP.resize(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, INF))));

    int answer = BFS(0, 0);
    return answer;
}