#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> myStack;

    for (const auto alphabet : s) {
        if (myStack.empty()) {
            myStack.push(alphabet);
            continue;
        }

        if (myStack.top() == alphabet) {
            myStack.pop();
            continue;
        }

        myStack.push(alphabet);
    }
   
    return myStack.empty();
}