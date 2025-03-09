#include <iostream>
#include <string>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N, K;
    cin >> N >> K;

    string input, answer;
    cin >> input;

    for (const char& number : input)
    {
        if (answer.empty() or number < answer.back())
        {
            answer.push_back(number);
            continue;
        }

        while (!answer.empty() and answer.back() < number and K > 0)
        {
            answer.pop_back();
            K--;
        }

        answer.push_back(number);
    }

    // K가 남았다면 뒷자리부터 제거
    while (K > 0)
    {
        answer.pop_back();
        K--;
    }

    cout << answer;
    return 0;
}