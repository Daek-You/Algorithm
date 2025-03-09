#include <string>
#include <queue>
using namespace std;

int solution(int n) {
    queue<int> myQueue;
    int answer = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
        myQueue.push(i);

        if (sum == n)
            answer++;
        else if (n < sum) {
            while (!myQueue.empty()) {
                int num = myQueue.front();
                myQueue.pop();
                sum -= num;

                if (sum == n)
                    answer++;
                else if (sum < n)
                    break;
            }
        }
    }

    return answer;
}