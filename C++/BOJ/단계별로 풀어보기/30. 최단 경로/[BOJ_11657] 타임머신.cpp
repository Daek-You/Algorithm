#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000

struct Edge {
    Edge() { }
    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) { }
    int from, to;
    long long cost;
};

bool BellmanFord(const vector<Edge>& busSchedules, vector<long long>& times, int nodeCount, int edgeCount, int start) {
    times[start] = 0;

    for (int i = 0; i < nodeCount; i++) {
        for (const auto& schedule : busSchedules) {
            int from = schedule.from;
            int to = schedule.to;
            long long cost = schedule.cost;
            long long newCost = times[from] + cost;

            if (times[from] != INF and newCost < times[to])
                times[to] = newCost;
        }
    }

    // 음의 사이클 점검
    for (const auto& schedule : busSchedules) {
        int from = schedule.from;
        int to = schedule.to;
        long long cost = schedule.cost;
        long long newCost = times[from] + cost;

        if (times[to] != INF and newCost < times[to])
            return true;
    }

    return false;
}

void Print(bool hasNegativeCycle, const vector<long long>& times, int cityCount) {
    if (hasNegativeCycle) {
        cout << "-1";
        return;
    }

    for (int i = 2; i <= cityCount; i++) {
        if (times[i] == INF)
            cout << "-1" << "\n";
        else
            cout << times[i] << "\n";
    }
}

int main() {
    FAST_IO
    int cityCount, busRouteCount;
    cin >> cityCount >> busRouteCount;

    vector<Edge> busSchedules;
    int from, to, cost;

    for (int i = 0; i < busRouteCount; i++) {
        cin >> from >> to >> cost;
        busSchedules.emplace_back(from, to, cost);
    }

    vector<long long> times(cityCount + 1, INF);
    bool hasNegativeCycle = BellmanFord(busSchedules, times, cityCount, busRouteCount, 1);

    Print(hasNegativeCycle, times, cityCount);
    return 0;
}