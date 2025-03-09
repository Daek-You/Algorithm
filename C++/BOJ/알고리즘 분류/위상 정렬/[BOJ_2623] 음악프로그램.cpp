#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int> Solution(const vector<vector<int>>& graph, vector<int>& inDegrees, int N) {
    vector<int> answers(N + 1);
    queue<int> nextSingers;

    for (int i = 1; i <= N; i++)
        if (inDegrees[i] == 0)
            nextSingers.push(i);
    
    for (int i = 1; i <= N; i++) {
        if (nextSingers.empty())
            return {0, 0};
        
        int singer = nextSingers.front();
        answers[i] = singer;
        nextSingers.pop();

        for (const auto& other : graph[singer]) {
            if (--inDegrees[other] == 0)
                nextSingers.push(other);
        }
    }

    return answers;
}

int main() {
    FAST_IO
    int N, M, singerCount;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> inDegrees(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> singerCount;
        int from, to;

        for (int i = 0; i < singerCount; i++) {
            cin >> to;

            if (i == 0) {
                from = to;
                continue;
            }

            graph[from].emplace_back(to);
            inDegrees[to]++;
            from = to;
        }
    }

    vector<int> answers = Solution(graph, inDegrees, N);
    for (int i = 1; i < answers.size(); i++)
        cout << answers[i] << "\n";

    return 0;
}