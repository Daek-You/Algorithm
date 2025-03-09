#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Point = pair<int, int>;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define EXTERNAL_AIR -1
#define AIR -2
#define REMOVE_TARGET_CHEESE -3


int MaxRow, MaxCol;
vector<vector<int>> Directions{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void FillExternalAirAndFindRemovingCheeses(vector<vector<int>>& field, queue<Point>& removeTargetCheeses, int startRow, int startCol)
{
    queue<Point> positions;
    field[startRow][startCol] = EXTERNAL_AIR;
    positions.emplace(Point(startRow, startCol));

    while (!positions.empty())
    {
        int row = positions.front().first;
        int col = positions.front().second;
        positions.pop();

        for (const vector<int>& direction : Directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (nextRow < 0 or nextRow >= MaxRow or nextCol < 0 or nextCol >= MaxCol)
                continue;

            if (field[nextRow][nextCol] == EXTERNAL_AIR or field[nextRow][nextCol] == REMOVE_TARGET_CHEESE)
                continue;
            
            if (field[nextRow][nextCol] >= 0)   // 치즈일 경우, 외부 접촉 공기 개수를 늘려주기
            {
                field[nextRow][nextCol]++;

                if (field[nextRow][nextCol] >= 2)
                {
                    field[nextRow][nextCol] = REMOVE_TARGET_CHEESE;
                    removeTargetCheeses.emplace(Point(nextRow, nextCol));
                }
                continue;
            }

            field[nextRow][nextCol] = EXTERNAL_AIR;
            positions.emplace(Point(nextRow, nextCol));
        }
    }
}

void Update(vector<vector<int>>& field, queue<Point>& removeTargetCheeses)
{
    int size = removeTargetCheeses.size();

    for (int i = 0; i < size; i++)
    {
        Point cheesePosition = removeTargetCheeses.front();
        int row = cheesePosition.first;
        int col = cheesePosition.second;

        removeTargetCheeses.pop();
        FillExternalAirAndFindRemovingCheeses(field, removeTargetCheeses, row, col);
    }
}

void Initialize(vector<vector<int>>& field)
{
    for (int row = 0; row < MaxRow; row++)
    {
        for (int col = 0; col < MaxCol; col++)
        {
            cin >> field[row][col];

            if (field[row][col] == 0)       field[row][col] = AIR;
            else if (field[row][col] == 1)  field[row][col] = 0;        // 치즈가 외부 공기와 접촉하는 칸 수 (우선 초깃값은 모두 0으로)
        }
    }
}

int main()
{
    FAST_IO
    cin >> MaxRow >> MaxCol;

    // 1. 입력 받고 세팅
    vector<vector<int>> field(MaxRow, vector<int>(MaxCol));
    Initialize(field);

    // 2. 외부 공기를 채우고, 그 과정에서 제거할 치즈들 찾기
    queue<Point> removeTargetCheeses;
    FillExternalAirAndFindRemovingCheeses(field, removeTargetCheeses, 0, 0);   // 가장자리에는 치즈가 없다고 했으므로 (0, 0)부터 시작

    // 3. 더 이상 제거할 치즈가 없을 때까지 반복
    int time = 0;
    while (!removeTargetCheeses.empty())
    {
        Update(field, removeTargetCheeses);
        time++;
    }

    cout << time;
    return 0;
}