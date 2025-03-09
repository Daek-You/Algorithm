#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int Solution(const vector<vector<int>>& graph, const vector<int>& workTimes, vector<int>& inDegrees, int N) {
    vector<int> totalTimes(N + 1);
    queue<int> works;

    for (int i = 1; i <= N; i++) {
        if (inDegrees[i] == 0) {
            works.push(i);
            totalTimes[i] = workTimes[i];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        int work = works.front();
        works.pop();

        for (const auto& other : graph[work]) {
            totalTimes[other] = max(totalTimes[other], totalTimes[work] + workTimes[other]);

            if (--inDegrees[other] == 0)
                works.push(other);
        }
    }

    return *max_element(totalTimes.begin(), totalTimes.end());
}

int main() {
    FAST_IO
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> workTimes(N + 1);
    vector<int> inDegrees(N + 1);
    int time, preWorkCount, preWork;

    for (int i = 1; i <= N; i++) {
        cin >> time >> preWorkCount;
        workTimes[i] = time;

        while (preWorkCount--) {
            cin >> preWork;
            graph[preWork].emplace_back(i);
            inDegrees[i]++;
        }
    }

    int answer = Solution(graph, workTimes, inDegrees, N);
    cout << answer;

    return 0;
}