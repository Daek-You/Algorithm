#include <vector>
using namespace std;
const int MOD = 1000000007;
const int WATER = -1;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> field(n + 1, vector<int>(m + 1));
    
    // 1. 물 웅덩이 위치 저장하기
    for (const auto& position : puddles)
    {
        int row = position[1], col = position[0];
        field[row][col] = WATER;
    }
    
    field[0][1] = 1;
    // 2. (왼쪽 + 위)를 더해가며 저장
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= m; col++)
        {
            if (field[row][col] == WATER)
            {
                field[row][col] = 0;
                continue;
            }
            
            field[row][col] = (field[row][col - 1] + field[row - 1][col]) % MOD;
        }
    }
    
    return field[n][m];
}