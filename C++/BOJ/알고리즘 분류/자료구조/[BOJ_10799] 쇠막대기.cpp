#include <iostream>
#include <string>
#include <stack>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    string parenthesises;
    cin >> parenthesises;

    stack<char> parenthesisStack;
    parenthesisStack.push(parenthesises[0]);

    int answer = 0;
    for (int i = 1; i < parenthesises.length(); i++)
    {
        if (parenthesisStack.empty() or parenthesises[i] == '(')
        {
            parenthesisStack.push(parenthesises[i]);
            continue;
        }

        // 레이저일 경우
        if (parenthesises[i - 1] == '(' and parenthesises[i] == ')')
        {
            parenthesisStack.pop();
            answer += parenthesisStack.size();
            continue;
        }

        // 쇠 막대기 끝 자락인 경우이므로, 맨 마지막 잘린 조각 1개 추가
        parenthesisStack.pop();
        answer += 1;
    }

    cout << answer;
    return 0;
}