#include <iostream>
#include <vector>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<Point> Directions { {}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };  // DUMMY, 동, 서, 북, 남
vector<int> SurfaceOfDice(6);

enum DIRECTION
{
    TOP,
    RIGHT,
    LEFT,
    FORWARD,
    BACK,
    DOWN,
};

bool Move(Point& dicePosition, const int directionIndex, const int maxRow, const int maxColumn)
{
    int nextDiceRow = dicePosition.first + Directions[directionIndex].first;
    int nextDiceColumn = dicePosition.second + Directions[directionIndex].second;

    if (nextDiceRow < 0 or nextDiceRow >= maxRow or nextDiceColumn < 0 or nextDiceColumn >= maxColumn)
        return false;

    switch(directionIndex)
    {
        case RIGHT:
        {
            int temp = SurfaceOfDice[DOWN];
            SurfaceOfDice[DOWN] = SurfaceOfDice[RIGHT];
            SurfaceOfDice[RIGHT] = SurfaceOfDice[TOP];
            SurfaceOfDice[TOP] = SurfaceOfDice[LEFT];
            SurfaceOfDice[LEFT] = temp;
            break;
        }

        case LEFT:
        {
            int temp = SurfaceOfDice[DOWN];
            SurfaceOfDice[DOWN] = SurfaceOfDice[LEFT];
            SurfaceOfDice[LEFT] = SurfaceOfDice[TOP];
            SurfaceOfDice[TOP] = SurfaceOfDice[RIGHT];
            SurfaceOfDice[RIGHT] = temp;
            break;
        }

        case FORWARD:
        {
            int temp = SurfaceOfDice[DOWN];
            SurfaceOfDice[DOWN] = SurfaceOfDice[FORWARD];
            SurfaceOfDice[FORWARD] = SurfaceOfDice[TOP];
            SurfaceOfDice[TOP] = SurfaceOfDice[BACK];
            SurfaceOfDice[BACK] = temp;
            break;
        }

        case BACK:
        {
            int temp = SurfaceOfDice[DOWN];
            SurfaceOfDice[DOWN] = SurfaceOfDice[BACK];
            SurfaceOfDice[BACK] = SurfaceOfDice[TOP];
            SurfaceOfDice[TOP] = SurfaceOfDice[FORWARD];
            SurfaceOfDice[FORWARD] = temp;
            break;
        }
    }
 
    dicePosition.first = nextDiceRow;
    dicePosition.second = nextDiceColumn;
    return true;
}

void Copy(vector<vector<int>>& map, int row, int column)
{
    if (map[row][column] == 0)
    {
        map[row][column] = SurfaceOfDice[DOWN];
        return;
    }

    SurfaceOfDice[DOWN] = map[row][column];
    map[row][column] = 0;
}

int main()
{
    FAST_IO

    // 1. 입력 받기
    int maxRow, maxColumn, numOfInstruction, directionIndex;
    Point dicePosition;

    cin >> maxRow >> maxColumn >> dicePosition.first >> dicePosition.second >> numOfInstruction;

    vector<vector<int>> map(maxRow, vector<int>(maxColumn));
    for (int row = 0; row < maxRow; row++)
        for (int column = 0; column < maxColumn; column++)
            cin >> map[row][column];

    // 2. 명령어 수행
    while (numOfInstruction--)
    {
        cin >> directionIndex;
        if (Move(dicePosition, directionIndex, maxRow, maxColumn))
        {
            cout << SurfaceOfDice[TOP] << "\n";
            Copy(map, dicePosition.first, dicePosition.second);
        }
    }

    return 0;
}