#include <iostream>
#include <stack>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

struct Data {
    Data() { }
    Data(int h, long long c) : height(h), count(c) { }
    int height;
    long long count;
};

int main() {
    FAST_IO
    int N;
    cin >> N;

    stack<Data> people;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        int nextHeight;
        cin >> nextHeight;

        int newCount = 1;
        while (!people.empty() and people.top().height < nextHeight) {
            answer += people.top().count;
            people.pop();
        }

        if (!people.empty()) {
            if (people.top().height == nextHeight) {
                answer += people.top().count;
                newCount = people.top().count + 1;

                if (people.size() > 1)
                    answer++;
                people.pop();
            }
            else {
                answer++;
            }
        }

        people.push(Data(nextHeight, newCount));
    }

    cout << answer;
    return 0;
}