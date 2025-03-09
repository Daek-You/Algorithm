#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<vector<int>> Graph;
vector<int> ConstructionTimes;
vector<int> InDegrees;

vector<int> Solution(int N) {
    vector<int> answers(N + 1);
    queue<int> buildings;

    for (int i = 1; i <= N; i++) {
        if (InDegrees[i] == 0) {
            buildings.push(i);
            answers[i] = ConstructionTimes[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        int v = buildings.front();
        buildings.pop();

        for (const auto& other : Graph[v]) {
            answers[other] = max(answers[other], answers[v] + ConstructionTimes[other]);

            if (--InDegrees[other] == 0)
                buildings.push(other);
        }
    }

    return answers;
}

int main() {
    FAST_IO
    int N, constructionTime, preBuilding;
    cin >> N;

    Graph.resize(N + 1);
    ConstructionTimes.resize(N + 1);
    InDegrees.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> constructionTime;
        ConstructionTimes[i] = constructionTime;

        while (true) {
            cin >> preBuilding;
            
            if (preBuilding == -1)
                break;
            Graph[preBuilding].emplace_back(i);
            InDegrees[i]++;
        }
    }

    vector<int> answers = Solution(N);
    for (int i = 1; i <= N; i++)
        cout << answers[i] << "\n";

    return 0;
}