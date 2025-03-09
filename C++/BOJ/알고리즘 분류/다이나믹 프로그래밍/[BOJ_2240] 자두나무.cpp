#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define NUMBER_ONE_TREE 1
#define NUMBER_TWO_TREE 2
#define NUM_OF_TREES 2

int main()
{
    FAST_IO
    int T, W;
    cin >> T >> W;

    vector<int> plums(T);
    for (int i = 0; i < T; i++) cin >> plums[i];

    vector<vector<vector<int>>> DP(W + 1, vector<vector<int>>(NUM_OF_TREES + 1, vector<int>(T + 1, 0)));
    for (int time = 1; time <= T; time++)
    {
        for (int move = 0; move <= W; move++)
        {
            if (move == 0)
            {
                DP[move][NUMBER_ONE_TREE][time] = DP[move][NUMBER_ONE_TREE][time - 1] + (plums[time - 1] == NUMBER_ONE_TREE);
            }
            else
            {
                DP[move][NUMBER_ONE_TREE][time] = max(DP[move][NUMBER_ONE_TREE][time - 1] + (plums[time - 1] == NUMBER_ONE_TREE), DP[move - 1][NUMBER_TWO_TREE][time - 1] + (plums[time - 1] == NUMBER_ONE_TREE));
                DP[move][NUMBER_TWO_TREE][time] = max(DP[move][NUMBER_TWO_TREE][time - 1] + (plums[time - 1] == NUMBER_TWO_TREE), DP[move - 1][NUMBER_ONE_TREE][time - 1] + (plums[time - 1] == NUMBER_TWO_TREE));
            }
        }
    }

    int answer = 0;
    for (int tree = 1; tree <= NUM_OF_TREES; tree++)
        for (int move = 0; move <= W; move++)
            answer = max(answer, DP[move][tree][T]);

    cout << answer;
    return 0;
}
