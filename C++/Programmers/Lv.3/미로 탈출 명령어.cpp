#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define DIRECTION_COUNT 4

vector<pair<int, int>> Directions { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
vector<char> Instructions { 'd', 'l', 'r', 'u' };
bool isFindAnswer = false;

int GetManhattanDistance(int x, int y, int r, int c)
{
    return abs(x - r) + abs(y - c);
}

void DFS(string path, string& answer, int x, int y, int r, int c, int depth, const int k, const int n, const int m)
{
    if (isFindAnswer or k - depth < GetManhattanDistance(x, y, r, c))
        return;
    
    if (depth == k)
    {
        if (x == r and y == c)
        {
            answer = path;
            isFindAnswer = true;
        }
        return;
    }

    for (int i = 0; i < DIRECTION_COUNT; i++)
    {
        int nextX = x + Directions[i].first;
        int nextY = y + Directions[i].second;

        if (nextX < 1 or nextX > n or nextY < 1 or nextY > m)
            continue;
        DFS(path + Instructions[i], answer, nextX, nextY, r, c, depth + 1, k, n, m);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";
    int minDistance = GetManhattanDistance(x, y, r, c);

    if ((k - minDistance) % 2 != 0 or k < minDistance)
        return "impossible";
    
    DFS("", answer, x, y, r, c, 0, k, n, m);
    return answer;
}