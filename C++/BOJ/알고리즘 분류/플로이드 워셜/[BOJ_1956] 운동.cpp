#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INFINITY 1000000000

int main()
{
    FAST_IO
    int V, E;
    cin >> V >> E;

    // 1. 초기화
    vector<vector<int>> distances(V + 1, vector<int>(V + 1, INFINITY));
    int from, to, distance;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> distance;
        distances[from][to] = distance;
    }

    // 2. 플로이드 워셜 알고리즘
    for (int mid = 1; mid <= V; mid++)
        for (int from = 1; from <= V; from++)
            for (int to = 1; to <= V; to++)
                distances[from][to] = min(distances[from][to], distances[from][mid] + distances[mid][to]);

    // 3. distances[i][j] + distances[j][i] 중에 최솟값 고르기
    int answer = INFINITY;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            if (distances[i][j] < INFINITY and distances[j][i] < INFINITY)
                answer = min(answer, distances[i][j] + distances[j][i]);

    if (answer == INFINITY)
        cout << "-1";
    else
        cout << answer;
    return 0;
}