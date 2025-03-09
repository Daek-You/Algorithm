#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Part = pair<int, int>;    // <부품 번호, 필요 개수>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int> Solution(const vector<vector<Part>>& parts, vector<int>& inDegrees, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    queue<int> nextParts;

    for (int i = 1; i <= N; i++) {
        if (inDegrees[i] == 0) {
            dp[i][i] = 1;
            nextParts.push(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int lowerPart = nextParts.front();
        nextParts.pop();

        for (const auto& upperLevel : parts[lowerPart]) {
            int upperPart = upperLevel.first;
            int upperPartCount = upperLevel.second;

            for (int i = 1; i <= N; i++)
                dp[upperPart][i] += dp[lowerPart][i] * upperPartCount;

            if (--inDegrees[upperPart] == 0)
                nextParts.push(upperPart);
        }
    }

    return dp[N];
 }


int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<vector<Part>> parts(N + 1, vector<Part>());
    vector<int> inDegrees(N + 1);
    int upperPart, lowerPart, count;

    for (int i = 0; i < M; i++) {
        cin >> upperPart >> lowerPart >> count;
        parts[lowerPart].emplace_back(upperPart, count);
        inDegrees[upperPart]++;
    }

    vector<int> answers = Solution(parts, inDegrees, N);

    for (int i = 1; i <= N; i++) {
        if (answers[i] != 0)
            cout << i << " " << answers[i] << "\n";
    }    

    return 0;
}