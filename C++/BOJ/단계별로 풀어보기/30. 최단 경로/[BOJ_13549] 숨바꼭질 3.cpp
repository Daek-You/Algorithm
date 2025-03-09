#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 100000
#define INF 1000000000

int Calculate(int node, int i) {
    switch(i) {
        case 0: return node - 1;
        case 1: return node + 1;
        case 2: return node * 2;
    }
    return 0;
}

int FindMinTime(vector<int>& times, int start, int K) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // <최소 시간, 노드>
    
    times[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int time = current.first;
        int node = current.second;
        pq.pop();

        for (int i = 0; i < 3; i++) {
            int next = Calculate(node, i);

            if (next < 0 or next > MAX or times[next] < time)
                continue;

            bool isTeleport = (i == 2);
            int nextTime = time + !isTeleport;

            if (next == K)
                times[K] = min(nextTime, times[K]);

            if (nextTime < times[next]) {
                times[next] = nextTime;
                pq.emplace(nextTime, next);
            }
        }
    }

    return times[K];
}

int main() {
    FAST_IO
    int N, K;
    cin >> N >> K;

    vector<int> times(MAX + 1, INF);
    int answer = FindMinTime(times, N, K);
    cout << answer;
    return 0;
}
