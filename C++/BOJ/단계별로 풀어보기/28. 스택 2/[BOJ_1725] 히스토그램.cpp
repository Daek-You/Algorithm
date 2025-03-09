#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main() {
    FAST_IO
    int N;
    cin >> N;

    vector<int> heights(N + 2);      // 앞뒤로 한 칸씩 패딩
    for (int i = 1; i <= N; i++)
        cin >> heights[i];

    stack<int> stacks;
    stacks.push(0);

    int answer = 0;
    for (int i = 1; i < N + 2; i++) {
        while (!stacks.empty() and heights[stacks.top()] > heights[i]) {
            int height = heights[stacks.top()];
            stacks.pop();

            int width = (i - 1) - stacks.top();
            int area = width * height;

            answer = max(answer, area);
        }

        stacks.push(i);
    }

    cout << answer;
    return 0;
}