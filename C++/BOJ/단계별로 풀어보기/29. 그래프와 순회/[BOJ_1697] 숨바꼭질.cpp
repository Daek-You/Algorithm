#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

const int MAX_VALUE = 100000;

int GetNextPosition(int current, int option) {
    switch (option) {
        case 0: return current - 1;
        case 1: return current + 1;
        case 2: return current * 2;
    }
    return current;
}

int main() {
    FAST_IO
    int N, K;
    cin >> N >> K;

    vector<int> numberLine(MAX_VALUE + 1, 1);
    queue<int> position;
    position.push(N);

    while (!position.empty()) {
        int current = position.front();
        position.pop();

        if (current == K)
            break;

        for (int i = 0; i < 3; i++) {
            int next = GetNextPosition(current, i);

            if (next < 0 or next > MAX_VALUE)
                continue;
            
            if (numberLine[next] != 1)
                continue;
            
            numberLine[next] = numberLine[current] + 1;
            position.push(next);
        }
    }

    cout << numberLine[K] - 1;       // 수빈이가 위치한 첫 번째 위치는 제외
    return 0;
}