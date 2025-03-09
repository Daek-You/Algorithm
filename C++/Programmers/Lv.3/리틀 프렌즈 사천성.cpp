#include <string>
#include <vector>
#include <map>
using namespace std;
using Point = pair<int, int>;
#define EMPTY '.'
#define OBSTACLE '*'

vector<Point> Directions;
int MaxRow, MaxColumn;
vector<string> Board;
map<char, vector<Point>> Tiles;
string Compare;

void Initialize(const int m, const int n, const vector<string>& board)
{
    MaxRow = m, MaxColumn = n;
    Board.clear();
    Tiles.clear();
    Compare.clear();
    Directions.clear();

    Board = board;
    Directions =  { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 상, 우, 하, 좌

    for (int r = 0; r < MaxRow; r++)
    {
        for (int c = 0; c < MaxColumn; c++)
        {
            Board[r][c] = board[r][c];

            if (Board[r][c] != EMPTY and Board[r][c] != OBSTACLE)
                Tiles[Board[r][c]].push_back({r, c});
        }
    }

    for (const auto &tile : Tiles)
        Compare.push_back(tile.first);
}

bool CanRemove(Point current, Point destination, int i, int curveCount)
{
    if (curveCount >= 2) return false;

    Point next = {current.first + Directions[i].first, current.second + Directions[i].second };

    if (next.first < 0 or next.first >= MaxRow or next.second < 0 or next.second >= MaxColumn)
        return false;
    
    if (next != destination and Board[next.first][next.second] != EMPTY)
        return false;
    
    if (next == destination)
        return true;
    
    int leftCurve = (i - 1 < 0) ? Directions.size() - 1 : i - 1;
    int rightCurve = (i + 1 >= Directions.size()) ? 0 : i + 1;

    bool straight = CanRemove(next, destination, i, curveCount);
    bool turnLeft = CanRemove(next, destination, leftCurve, curveCount + 1);
    bool turnRight = CanRemove(next, destination, rightCurve, curveCount + 1);

    return straight + turnLeft + turnRight;
}

string GetRemoveSequence()
{
    string sequence = "";

    while (!Compare.empty())
    {
        bool isSucceed = false;

        for (int ix = 0; ix < Compare.length(); ix++)
        {
            char label = Compare[ix];
            Point current = Tiles[label][0], destination = Tiles[label][1];

            for (int di = 0; di < Directions.size(); di++)
            {
                if (CanRemove(current, destination, di, 0))
                {
                    for (const Point &tile : Tiles[label])
                        Board[tile.first][tile.second] = EMPTY;

                    Tiles.erase(label);
                    Compare.erase(ix, 1);

                    sequence.push_back(label);
                    isSucceed = true;
                    break;
                }
            }

            if (isSucceed)
                break;
        }

        if (!isSucceed)
            return "IMPOSSIBLE";
    }

    return sequence;
}

string solution(int m, int n, vector<string> board)
{
    Initialize(m, n, board);
    string answer = GetRemoveSequence();
    return answer;
}