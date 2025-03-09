#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int> GetSolvedOrder(const vector<vector<int>>& graph, vector<int>& inDegrees, int N) {
    priority_queue<int, vector<int>, greater<int>> problems;
    for (int i = 1; i <= N; i++) {
        if (inDegrees[i] == 0)
            problems.push(i);
    }

    vector<int> answers(N + 1);
    for (int i = 1; i <= N; i++) {
        
        int problem = problems.top();
        problems.pop();
        answers[i] = problem;

        for (const auto& other : graph[problem]) {
            if (--inDegrees[other] == 0)
                problems.push(other);
        }
    }

    return answers;
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    int from, to;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> inDegrees(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        graph[from].emplace_back(to);
        inDegrees[to]++;
    }

    vector<int> answers = GetSolvedOrder(graph, inDegrees, N);
    for (int i = 1; i <= N; i++)
        cout << answers[i] << " ";
    
    return 0;
}