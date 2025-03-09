#include <vector>
using namespace std;
#define HOLE    0
#define DOME    1
#define DIRECTION_COUNT 4

int KeySize, LockSize, MapSize, NumOfLockHoles;
vector<vector<int>> Map;
vector<vector<int>> Keys[DIRECTION_COUNT];  // 90, 180, 270도 회전한 결과들

vector<vector<int>> Rotate90Clockwise(const vector<vector<int>>& matrix)
{
    vector<vector<int>> rotated(KeySize, vector<int>(KeySize));

    for (int row = 0; row < KeySize; row++)
        for (int column = 0; column < KeySize; column++)
            rotated[column][KeySize - row - 1] = matrix[row][column];
    
    return rotated;
}

void Initialize(const vector<vector<int>>& key, const vector<vector<int>>& lock)
{
    // 1. Map 세팅
    KeySize = key.size(), LockSize = lock.size();
    MapSize = (KeySize - 1) + LockSize + (KeySize - 1);
    NumOfLockHoles = 0;

    Map.resize(MapSize, vector<int>(MapSize));
    int startRow = KeySize - 1, startColumn = KeySize - 1;

    for (int row = startRow; row < startRow + LockSize; row++)
    {
        for (int column = startColumn; column < startColumn + LockSize; column++)
        {
            Map[row][column] = lock[row - startRow][column - startColumn];

            if (Map[row][column] == HOLE)   NumOfLockHoles++;
        }
    }
    
    // 2. 90, 180, 270도 순으로 회전한 키 정보 저장
    for (int i = 0; i < DIRECTION_COUNT; i++)
    {
        Keys[i].resize(KeySize, vector<int>(KeySize));

        if (i == 0)
        {
            Keys[i] = key;
            continue;
        }

        Keys[i] = Rotate90Clockwise(Keys[i - 1]);
    }
}

bool IsMatch(int row, int column, const vector<vector<int>>& key)
{
    int lockHoles = NumOfLockHoles;
    for (int r = 0; r < KeySize; r++)
    {
        for (int c = 0; c < KeySize; c++)
        {
            int newRow = row + r;
            int newColumn = column + c;

            // 자물쇠 영역 내에서만 검사
            if (KeySize - 1 <= newRow and newRow < LockSize + KeySize - 1 and
                KeySize - 1 <= newColumn and newColumn < LockSize + KeySize - 1)
            {
                if (key[r][c] == DOME && Map[newRow][newColumn] == DOME)
                    return false;
                if (key[r][c] == DOME && Map[newRow][newColumn] == HOLE)
                    lockHoles--;
            }
        }
    }

    return lockHoles == 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    Initialize(key, lock);

    for (int row = 0; row < LockSize + KeySize - 1; row++)
        for (int column = 0; column < LockSize + KeySize - 1; column++)
            for (int i = 0; i < DIRECTION_COUNT; i++)
                if (IsMatch(row, column, Keys[i]))
                    return true;
    
    return false;
}
