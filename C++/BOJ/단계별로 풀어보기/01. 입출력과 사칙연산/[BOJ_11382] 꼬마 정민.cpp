#include <iostream>
#include <string>
using namespace std;

int main() {
    long long number;
    long long answer = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> number;
        answer += number;
    }

    cout << answer;
    return 0;
}