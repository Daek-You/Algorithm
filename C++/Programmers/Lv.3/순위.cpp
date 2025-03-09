#include <vector>
using namespace std;

#define VICTORY true
#define UNKNOWN false

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> table(n + 1, vector<bool>(n + 1, UNKNOWN));
    for (const vector<int>& result : results)
    {
        int winner = result[0], loser = result[1];
        table[winner][loser] = VICTORY;
    }

    for (int mid = 1; mid <= n; mid++)
        for (int from = 1; from <= n; from++)
            for (int to = 1; to <= n; to++)
                if (table[from][mid] == VICTORY and table[mid][to] == VICTORY)
                    table[from][to] = VICTORY;

    int answer = 0;
    for (int a = 1; a <= n; a++)
    {
        int winCount = 0;
        for (int b = 1; b <= n; b++)
        {
            if (table[a][b] or table[b][a])
                winCount++;
        }

        if (winCount == n - 1)
            answer++;
    }

    return answer;
}
