#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;
#define MAX_RANGE 100
#define DIRECTION_COUNT 4
#define INVALID 0
#define OUTLINE 1

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<vector<int>> Board;

void CreateRectangle(const vector<vector<int>>& rectangles)
{
    for (const vector<int>& rectangle : rectangles)
    {
        int leftLowerX = rectangle[0] * 2, leftLowerY = rectangle[1] * 2;
        int rightUpperX = rectangle[2] * 2, rightUpperY = rectangle[3] * 2;

        // 직사각형의 외곽선 채우기
        for (int y = leftLowerY; y <= rightUpperY; y++)
            for (int x = leftLowerX; x <= rightUpperX; x++)
                Board[y][x] = 1;
    }

    for (const vector<int>& rectangle : rectangles)
    {
        int leftLowerX = rectangle[0] * 2, leftLowerY = rectangle[1] * 2;
        int rightUpperX = rectangle[2] * 2, rightUpperY = rectangle[3] * 2;

        // 내부는 다시 0으로
        for (int y = leftLowerY + 1; y < rightUpperY; y++)
            for (int x = leftLowerX + 1; x < rightUpperX; x++)
                Board[y][x] = 0;
    }
}

int BFS(int characterX, int characterY, const int itemX, const int itemY)
{
    queue<Point> positions;
    positions.push(Point(characterY, characterX));

    while (!positions.empty())
    {
        int y = positions.front().first;
        int x = positions.front().second;
        positions.pop();

        if (x == itemX and y == itemY)
            break;
        
        for (int i = 0; i < DIRECTION_COUNT; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextX < 0 or nextX > MAX_RANGE or nextY < 0 or nextY > MAX_RANGE)
                continue;

            if (Board[nextY][nextX] == OUTLINE)
            {
                positions.push(Point(nextY, nextX));
                Board[nextY][nextX] = Board[y][x] + 1;
            }            
        }
    }

    return Board[itemY][itemX] / 2;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    Board.resize(MAX_RANGE + 1, vector<int>(MAX_RANGE + 1, INVALID));
    CreateRectangle(rectangle);

    int answer = BFS(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    return answer;
}