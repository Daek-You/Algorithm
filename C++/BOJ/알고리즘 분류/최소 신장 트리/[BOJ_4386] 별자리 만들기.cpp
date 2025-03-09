#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <float.h>

using namespace std;
using Point = pair<float, float>;
using Data = pair<float, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

float GetDistance(const Point& p1, const Point& p2) {
    float deltaX = p2.first - p1.first;
    float deltaY = p2.second - p1.second;
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

float Prim(const vector<vector<float>>& distances, int start) {
    vector<bool> MST(distances.size(), false);
    MST[start] = true;

    priority_queue<Data, vector<Data>, greater<Data>> edges;
    for (int i = 0; i < distances[start].size(); i++) {
        if (i == start)
            continue;
        edges.emplace(distances[start][i], i);
    }

    float answer = 0;
    while (!edges.empty()) {
        float distance = edges.top().first;
        int node = edges.top().second;
        edges.pop();

        if (MST[node])
            continue;
        
        MST[node] = true;
        answer += distance;

        for (int i = 0; i < distances[node].size(); i++) {
            if (i == node or MST[i])
                continue;
            edges.emplace(distances[node][i], i);
        }
    }

    return answer;
}

int main() {
    FAST_IO
    int N;
    cin >> N;

    // 0번 ~ n-1 번이라고 각각 별자리 번호를 부여
    vector<Point> positions(N);
    vector<vector<float>> distances(N, vector<float>(N, FLT_MAX));
    for (int current = 0; current < N; current++) {
        float x, y;
        cin >> x >> y;
        positions[current] = make_pair(x, y);

        for (int previous = current - 1; previous >= 0; previous--) {
            float distance = GetDistance(positions[current], positions[previous]);
            distances[current][previous] = distances[previous][current] = distance;
        }
    }

    float answer = Prim(distances, 0);
    cout << answer;

    return 0;
}