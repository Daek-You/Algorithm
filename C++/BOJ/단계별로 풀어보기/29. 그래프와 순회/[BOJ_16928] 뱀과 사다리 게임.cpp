#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

const int BOARD_SIZE = 100;

int BFS(vector<int>& teleports, vector<int>& diceCounts) {
    queue<int> indexes;
    indexes.push(1);

    while (!indexes.empty()) {
        int current = indexes.front();
        indexes.pop();

        for (int i = 1; i <= 6; i++) {
            int next = current + i;

            if (next > BOARD_SIZE or diceCounts[next] != 0)
                continue;
            
            if (next == BOARD_SIZE)
                return diceCounts[current] + 1;

            while (teleports[next] != 0)
                next = teleports[next];

            if (diceCounts[next] != 0)
                continue;

            diceCounts[next] = diceCounts[current] + 1;
            indexes.emplace(next);
        }
    }

    return 0;
}


void AddTeleportInformations(vector<int>& next, int N) {
    int from, to;

    for (int i = 0; i < N; i++) {
        cin >> from >> to;
        next[from] = to;
    }
}

int main() {
    FAST_IO

    // 1. 초기화
    vector<int> teleports(BOARD_SIZE + 1, 0);
    vector<int> diceCounts(BOARD_SIZE + 1, 0);

    // 2. 사다리랑 뱀 요소 추가
    int ladderCount, snakeCount;
    cin >> ladderCount >> snakeCount;

    AddTeleportInformations(teleports, ladderCount);
    AddTeleportInformations(teleports, snakeCount);

    // 3. BFS 탐색 시작
    int answer = BFS(teleports, diceCounts);
    cout << answer;
    return 0;
}