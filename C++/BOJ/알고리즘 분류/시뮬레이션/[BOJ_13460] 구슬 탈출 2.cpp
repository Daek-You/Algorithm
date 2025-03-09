#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define EMPTY       '.'
#define OBSTACLE    '#'
#define HOLE        'O'
#define RED_BALL    'R'
#define BLUE_BALL   'B'

struct BallInfo
{
    BallInfo() { }
    BallInfo(Point redBall, Point blueBall, int count) : redBall(redBall), blueBall(blueBall), count(count) { }
    Point redBall;
    Point blueBall;
    int count = 0;
};

int MaxRow, MaxColumn;
vector<vector<char>> Board;
vector<Point> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
BallInfo StartingPoint;

void Initialize()
{
    cin >> MaxRow >> MaxColumn;
    Board.resize(MaxRow, vector<char>(MaxColumn));

    for (int row = 0; row < MaxRow; row++)
    {
        for (int column = 0; column < MaxColumn; column++)
        {
            cin >> Board[row][column];

            if (Board[row][column] == RED_BALL)
                StartingPoint.redBall = make_pair(row, column);
            else if (Board[row][column] == BLUE_BALL)
                StartingPoint.blueBall = make_pair(row, column);
        }
    }
}

int Move(int& row, int& column, Point direction)
{
    int moveDistance = 0;

    while (true)
    {
        int nextRow = row + direction.first;
        int nextColumn = column + direction.second;

        if (Board[nextRow][nextColumn] == OBSTACLE or Board[row][column] == HOLE)
            break;
        
        row = nextRow;
        column = nextColumn;
        moveDistance++;
    }

    return moveDistance;
}

int Solution()
{
    int answer = -1;
    bool visited[MaxRow][MaxColumn][MaxRow][MaxColumn] = {false, };
    
    queue<BallInfo> balls;
    balls.push(StartingPoint);

    int redBallRow = StartingPoint.redBall.first, redBallColumn = StartingPoint.redBall.second;
    int blueBallRow = StartingPoint.blueBall.first, blueBallColumn = StartingPoint.blueBall.second; 
    visited[redBallRow][redBallColumn][blueBallRow][blueBallColumn] = true;

    while (!balls.empty())
    {
        BallInfo currentBall = balls.front();
        balls.pop();

        redBallRow = currentBall.redBall.first, redBallColumn = currentBall.redBall.second;
        blueBallRow = currentBall.blueBall.first, blueBallColumn = currentBall.blueBall.second;

        if (currentBall.count >= 10)
            break;

        for (const Point& direction : Directions)
        {
            int nextRedBallRow = redBallRow, nextRedBallColumn = redBallColumn;
            int nextBlueBallRow = blueBallRow, nextBlueBallColumn = blueBallColumn;

            int redBallMoveDistance = Move(nextRedBallRow, nextRedBallColumn, direction);
            int blueBallMoveDistance = Move(nextBlueBallRow, nextBlueBallColumn, direction);

            if (Board[nextBlueBallRow][nextBlueBallColumn] == HOLE)
                continue;
            if (Board[nextRedBallRow][nextRedBallColumn] == HOLE)
                return currentBall.count + 1;

            if (nextRedBallRow == nextBlueBallRow and nextRedBallColumn == nextBlueBallColumn)
            {
                if (redBallMoveDistance > blueBallMoveDistance)
                    nextRedBallRow -= direction.first, nextRedBallColumn -= direction.second;
                else
                    nextBlueBallRow -= direction.first, nextBlueBallColumn -= direction.second; 
            }

            if (visited[nextRedBallRow][nextRedBallColumn][nextBlueBallRow][nextBlueBallColumn])
                continue;
            
            visited[nextRedBallRow][nextRedBallColumn][nextBlueBallRow][nextBlueBallColumn] = true;
            balls.emplace(BallInfo(Point(nextRedBallRow, nextRedBallColumn), Point(nextBlueBallRow, nextBlueBallColumn), currentBall.count + 1));

        }
    }

    return answer;
}

int main()
{
    FAST_IO
    Initialize();

    int answer = Solution();
    cout << answer;
    return 0;
}