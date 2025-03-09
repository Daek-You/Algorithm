#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    string A, B;
    cin >> A >> B;

    vector<vector<int>> DP(A.length() + 1, vector<int>(B.length() + 1));

    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    cout << DP[A.length()][B.length()];
    return 0;
}