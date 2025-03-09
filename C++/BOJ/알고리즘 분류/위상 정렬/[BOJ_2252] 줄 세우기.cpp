#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void TopologicalSort(const vector<vector<int>>& graph, vector<int>& answers, vector<int>& inDegrees, int N) {
    queue<int> students;

    for (int i = 1; i <= N; i++)
        if (inDegrees[i] == 0)
            students.push(i);
    
    for (int i = 1; i <= N; i++) {
        if (students.empty())   // 사이클 발생
            return;
        
        int node = students.front();
        answers[i] = node;
        students.pop();

        for (const int& otherNode : graph[node]) {
            if (--inDegrees[otherNode] == 0)
                students.push(otherNode);
        }
    }
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    int front, back;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> inDegrees(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> front >> back;
        graph[front].emplace_back(back);
        inDegrees[back]++;
    }

    vector<int> answers(N + 1);
    TopologicalSort(graph, answers, inDegrees, N);

    for (int i = 1; i <= N; i++)
        cout << answers[i] << " ";

    return 0;
}