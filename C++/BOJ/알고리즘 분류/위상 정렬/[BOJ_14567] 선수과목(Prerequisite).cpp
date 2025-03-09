#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int> TopologicalSort(const vector<vector<int>>& subjects, vector<int>& inDegrees, int N) {
    vector<int> answers(N + 1);
    queue<int> nextSubjects;

    for (int i = 1; i <= N; i++) {
        if (inDegrees[i] == 0) {
            nextSubjects.push(i);
            answers[i] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        int v = nextSubjects.front();
        nextSubjects.pop();

        for (const auto& subject : subjects[v]) {
            if (--inDegrees[subject] == 0) {
                answers[subject] = answers[v] + 1;
                nextSubjects.push(subject);
            }
        }
    }

    return answers;
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<vector<int>> prerequisiteSubjects(N + 1, vector<int>());
    vector<int> inDegrees(N + 1);
    int from, to;

    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        prerequisiteSubjects[from].emplace_back(to);
        inDegrees[to]++;
    }

    vector<int> answers = TopologicalSort(prerequisiteSubjects, inDegrees, N);
    for (int i = 1; i <= N; i++)
        cout << answers[i] << " ";

    return 0;
}