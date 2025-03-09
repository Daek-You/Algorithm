#include <iostream>
#include <vector>

using namespace std;
using Direction = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define UNCLEANED_BLANK 0
#define WALL  1
#define CLEANED_BLANK   2

int MaxRow, MaxColumn;
vector<Direction> Directions { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 북, 동, 남, 서
vector<vector<int>> Room;

void Initialize(int& row, int& column, int& forward)
{
    cin >> MaxRow >> MaxColumn;
    Room.resize(MaxRow, vector<int>(MaxColumn));

    cin >> row >> column >> forward;

    for (int i = 0; i < MaxRow; i++)
        for (int j = 0; j < MaxColumn; j++)
            cin >> Room[i][j];
}

int GetCleanedRoomCount(int row, int column, int forward)
{
    int cleanedRoomCount = 0;

    while (true)
    {
        if (Room[row][column] == UNCLEANED_BLANK)
        {
            Room[row][column] = CLEANED_BLANK;
            cleanedRoomCount++;
        }

        bool isExistUncleanedRoom = false;

        for (int _ = 0; _ < Directions.size(); _++)
        {
            forward = (0 <= forward - 1) ? forward - 1 : Directions.size() - 1;  // 반시계방향으로 90도 회전
            int nextRow = row + Directions[forward].first;
            int nextColumn = column + Directions[forward].second;

            if (Room[nextRow][nextColumn] == UNCLEANED_BLANK)
            {
                row = nextRow, column = nextColumn;
                isExistUncleanedRoom = true;
                break;
            }
        }

        if (!isExistUncleanedRoom)
        {
            int back = (forward + 2) % Directions.size();
            int nextRow = row + Directions[back].first;
            int nextColumn = column + Directions[back].second;

            if (Room[nextRow][nextColumn] == WALL) break;
            row = nextRow, column = nextColumn;
        }
    }

    return cleanedRoomCount;
}

int main()
{
    FAST_IO
    int row, column, forward;
    Initialize(row, column, forward);

    int answer = GetCleanedRoomCount(row, column, forward);
    cout << answer;
    return 0;
}