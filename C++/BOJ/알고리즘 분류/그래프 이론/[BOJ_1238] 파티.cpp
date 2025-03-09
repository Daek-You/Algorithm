#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Cost = pair<int, int>;    // <시간, 목적지 마을>

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 1000000000

void Dijkstra(const vector<vector<Cost>>& lanes, vector<int>& times, int N, int i) {
    priority_queue<Cost, vector<Cost>, greater<Cost>> pq;
    times[i] = 0;
    pq.emplace(0, i);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();

        if (times[city] < cost)
            continue;
        
        for (const auto& adjacentCity : lanes[city]) {
            int otherCityCost = adjacentCity.first;
            int otehrCity = adjacentCity.second;
            int newCost = cost + otherCityCost;

            if (newCost < times[otehrCity]) {
                times[otehrCity] = newCost;
                pq.emplace(newCost, otehrCity);
            }
        }
    }
}

int main() {
    FAST_IO
    int N, M, X;
    cin >> N >> M >> X;

    int from, to, time;
    vector<vector<Cost>> lanes(N + 1, vector<Cost>());
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> time;
        lanes[from].emplace_back(time, to);
    }

    // 각 마을에서 가는 비용 계산
    vector<int> answers(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        vector<int> times(N + 1, MAX);
        Dijkstra(lanes, times, N, i);
        answers[i] += times[X];
    }

    // X 마을에서 각 마을로 가는 비용 계산
    vector<int> times(N + 1, MAX);
    Dijkstra(lanes, times, N, X);

    // 총 왕복 비용 계산 후, 가장 오래 걸리는 친구의 시간 출력
    for (int i = 1; i <= N; i++)
        answers[i] += times[i];
    
    sort(answers.begin(), answers.end(), greater<int>());
    cout << answers[0];

    return 0;
}