#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> myStack;
    
    for(const auto parenthesis : s) {
        if (myStack.empty() and parenthesis == ')')
            return false;
        
        if (parenthesis == '(')
            myStack.push(parenthesis);
        
        else if (parenthesis == ')') {
            while(!myStack.empty())
            {
                char top = myStack.top();
                myStack.pop();
                
                if(top == '(')
                    break;
            }
        }
    }

    return myStack.empty() ? true : false;
}