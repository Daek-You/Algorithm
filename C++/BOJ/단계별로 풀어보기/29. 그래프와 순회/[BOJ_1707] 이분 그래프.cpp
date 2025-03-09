#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

string BFS(vector<int>& colors, vector<vector<int>>& edges, int V);
/* -------------------------------------------------------------------------*/

const int NONE = 0;
const int PAINTED_COLOR = 1;

int main() {
    FAST_IO
    int K, V, E;
    cin >> K;

    for (int T = 0; T < K; T++) {
        cin >> V >> E;

        vector<vector<int>> edges(V + 1, vector<int>());
        int from, to;
        for (int i = 0; i < E; i++) {
            cin >> from >> to;
            edges[from].push_back(to);
            edges[to].push_back(from);
        }

        vector<int> colors(V + 1, NONE);
        string answer = BFS(colors, edges, V);
        cout << answer << "\n";
        }

    return 0;
}

string BFS(vector<int>& colors, vector<vector<int>>& edges, int N) {
    for (int i = 1; i <= N; i++) {
        if (colors[i] != NONE)
            continue;
        
        queue<int> vertexes;
        vertexes.emplace(i);
        colors[i] = PAINTED_COLOR;

        while (!vertexes.empty()) {
            int V = vertexes.front();
            vertexes.pop();

            for (const int& next : edges[V]) {
                if (colors[next] != NONE) {
                    if (colors[V] == colors[next])
                        return "NO";
                    continue;
                }
            
                vertexes.emplace(next);
                colors[next] = -colors[V];
            }
        }
    }

    return "YES";
}

