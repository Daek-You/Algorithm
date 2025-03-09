#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Direction = pair<int, int>;

class Board
{
public:
    Board();

    void StartGame();
    int ShowPlayTime() { return _playTime; }
private:
    void CheckTurning();
    void CheckApple();

private:
    struct TurningData
    {
        TurningData() { }
        TurningData(int time, char directionMark) : _time(time), _directionMark(directionMark) { }
        int     _time;
        char    _directionMark;
    };

    struct Position
    {
        Position() { }
        Position(int row, int col) : _row(row), _col(col) { }
        Position operator+(const Direction& other) { return Position(_row + other.first, _col + other.second); }

        int _row;
        int _col;
    };

private:
    vector<vector<int>> _board;
    queue<TurningData>  _turningData;
    queue<Direction>    _tailMoveDirections;

    // (-1, 0):상, (0, 1):우, (1, 0):하, (0, -1):좌
    vector<Direction> _directions { {-1, 0}, { 0, 1 }, { 1, 0 }, { 0, -1 } };
private:
    int _directionIdx = 1;
    int _playTime = 0;
    int _N;

    Position _head = Position(0, 0);       // 머리 위치
    Position _tail = Position(0, 0);       // 꼬리 위치
private:
    const int EMPTY = 0;
    const int SNAKE = 1;
    const int APPLE = 2;
};

Board::Board()
{
    int N, appleCount, turningInformations;
    cin >> N >> appleCount;

    _N = N;

    // 1. N x N 보드판 만들기
    _board.resize(N);
    for (int i = 0; i < N; i++)
        _board[i].resize(N);

    _board[0][0] = SNAKE;  // 뱀 처음 위치 등록

    // 2. 맵에 사과 채우기
    for (int i = 0; i < appleCount; i++)
    {
        int row, col;
        cin >> row >> col;
        _board[row - 1][col - 1] = APPLE;
    }

    // 3. 방향 전환 포인트 저장하기
    cin >> turningInformations;
    for (int i = 0; i < turningInformations; i++)
    {
        int time;
        char mark;
        cin >> time >> mark;
        _turningData.emplace(TurningData(time, mark));
    }
}

void Board::CheckTurning()
{
    if (!_turningData.empty())
    {
        TurningData data = _turningData.front();

        if (data._time == _playTime)
        {
            _turningData.pop();
            int addIdx = (data._directionMark == 'L') ? -1 : 1;

            if (_directionIdx == 0 and addIdx == -1)
            {
                _directionIdx = _directions.size() - 1;
                return;
            }

            _directionIdx = (_directionIdx + addIdx) % _directions.size();
        }
    }
}

void Board::CheckApple()
{
    if (_tailMoveDirections.empty())
        return;

    // 사과가 없다면, 꼬리 이동
    if (_board[_head._row][_head._col] != APPLE)
    {
        Direction next = _tailMoveDirections.front();
        _tailMoveDirections.pop();

        _board[_tail._row][_tail._col] = EMPTY;
        _tail = _tail + next;
    }
}

void Board::StartGame()
{
    while (true)
    {
        // 1. 방향을 바꿔야 하는지 확인
        CheckTurning();
        _playTime++;

        _head = _head + _directions[_directionIdx];
        _tailMoveDirections.emplace(_directions[_directionIdx]);

        // 2. 벽에 부딪혔다면 게임 종료
        if (_head._row < 0 or _head._row >= _N or _head._col < 0 or _head._col >= _N)
            break;

        // 3. 머리가 자기 몸과 부딪히면 게임 종료
        if (_board[_head._row][_head._col] == SNAKE)
            break;

        // 4. 사과 여부 확인
        CheckApple();

        _board[_head._row][_head._col] = SNAKE;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    Board gameBoard;
    gameBoard.StartGame();
    cout << gameBoard.ShowPlayTime();
    return 0;
}