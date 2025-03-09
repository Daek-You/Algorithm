#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int TopologicalSort(const vector<vector<int>>& graph, const vector<int>& constructionTimes, vector<int>& inDegrees, int N, int W) {
    vector<int> answer(N + 1, 0);
    queue<int> buildings;

    for (int i = 1; i <= N; i++)
        if (inDegrees[i] == 0) {
            buildings.push(i);
            answer[i] = constructionTimes[i];
        }
    
    for (int i = 1; i <= N; i++) {
        int current = buildings.front();
        buildings.pop();

        for (const auto& next : graph[current]) {
            answer[next] = max(answer[next], answer[current] + constructionTimes[next]);
            inDegrees[next]--;

            if (inDegrees[next] == 0)
                buildings.push(next);
        }
    }

    return answer[W];
}


int main() {
    FAST_IO
    int T, N, K;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        vector<int> constructionTimes(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> constructionTimes[i];

        int previousBuilding, postBuilding, targetBuilding;
        vector<vector<int>> graph(N + 1, vector<int>());
        vector<int> inDegrees(N + 1, 0);

        for (int i = 0; i < K; i++) {
            cin >> previousBuilding >> postBuilding;
            graph[previousBuilding].push_back(postBuilding);
            inDegrees[postBuilding]++;
        }

        cin >> targetBuilding;
        
        int answer = TopologicalSort(graph, constructionTimes, inDegrees, N, targetBuilding);
        cout << answer << "\n";
    }

    return 0;
}