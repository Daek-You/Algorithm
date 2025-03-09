#include <vector>
using namespace std;
#define MOD 20170805
#define PASSABLE		0
#define STOP			1
#define ONLY_STRAIGHT	2

#define DOWN			0
#define RIGHT			1
#define DIRECTION_COUNT	2


int solution(int m, int n, vector<vector<int>> city_map)
{
	vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(DIRECTION_COUNT, 0)));
	int startRow = 1, startColumn = 1;
	dp[startRow][startColumn][DOWN] = dp[startRow][startColumn][RIGHT] = 1;

	for (int row = 1; row <= m; row++)
	{
		for (int column = 1; column <= n; column++)
		{
			if (city_map[row - 1][column - 1] == PASSABLE)
			{
				dp[row][column][DOWN] = (dp[row][column][DOWN] + dp[row - 1][column][DOWN] + dp[row][column - 1][RIGHT]) % MOD;
				dp[row][column][RIGHT] = (dp[row][column][RIGHT] + dp[row - 1][column][DOWN] + dp[row][column - 1][RIGHT]) % MOD;
			}

			else if (city_map[row - 1][column - 1] == STOP)
			{
				dp[row][column][DOWN] = dp[row][column][RIGHT] = 0;
			}
			
			else if (city_map[row - 1][column - 1] == ONLY_STRAIGHT)
			{
				dp[row][column][DOWN] = dp[row - 1][column][DOWN];
				dp[row][column][RIGHT] = dp[row][column - 1][RIGHT];
			}
		}
	}


    return dp[m][n][RIGHT];
}