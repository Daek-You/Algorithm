#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Expression {
public:
    Expression(const string& expression) {
        string digitBuffer;

        for (const auto element : expression) {
            if (isdigit(element)) {
                digitBuffer.push_back(element);
                continue;
            }

            _operatorTypes.insert(element);
            _splitedExpression.push_back(digitBuffer);

            string _operator;
            _operator.push_back(element);

            _splitedExpression.push_back(_operator);
            digitBuffer.clear();
        }

        _splitedExpression.push_back(digitBuffer);
    }

public:
    vector<string> _splitedExpression;
    set<char> _operatorTypes;
};


vector<map<char, int>> GetOperatorsPermutation(set<char> operators) {
    string strOpreators;
    vector<map<char, int>> results;

    for (const auto _operator : operators)
        strOpreators.push_back(_operator);


    do {
        map<char, int> priority;

        for (int i = 0; i < strOpreators.length(); i++)
            priority[strOpreators[i]] = i;

        results.push_back(priority);
    } while (next_permutation(strOpreators.begin(), strOpreators.end()));

    return results;
}


vector<string> ConvertInfixToPostFix(const vector<string>& splitedInfixExpression, const map<char, int>& operatorPriority) {
    vector<string> postFix;
    stack<char> operators;

    for (auto element : splitedInfixExpression) {
        if (isdigit(element[0])) {
            postFix.push_back(element);
            continue;
        }

        if (operators.empty()) {
            operators.push(element[0]);
            continue;
        }

        int currentOpratorPriority = operatorPriority.find(element[0])->second;
        int stackTopOperatorPriority = operatorPriority.find(operators.top())->second;

        if (stackTopOperatorPriority < currentOpratorPriority) {
            operators.push(element[0]);
        }

        else {
            while (true) {
                if (operators.empty())
                    break;

                char targetOperator = operators.top();
                int priority = operatorPriority.find(targetOperator)->second;

                if (priority < currentOpratorPriority)
                    break;

                string strOperator;
                strOperator.push_back(targetOperator);
                postFix.push_back(strOperator);
                operators.pop();
            }

            operators.push(element[0]);
        }
    }

    while (!operators.empty()) {
        char targetOperator = operators.top();
        operators.pop();

        string strOperator;
        strOperator.push_back(targetOperator);
        postFix.push_back(strOperator);
    }

    return postFix;
}


long long Calculate(const vector<string>& postFixExpression) {

    stack<string> myStack;

    for (const auto element : postFixExpression) {
        if (isdigit(element[0])) {
            myStack.push(element);
            continue;
        }

        long long num2 = stoll(myStack.top());
        myStack.pop();

        long long num1 = stoll(myStack.top());
        myStack.pop();

        long long result = 0;
        switch (element[0]) {

            case '+':
                result = num1 + num2;
                break;

            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;
        }

        myStack.push(to_string(result));
    }


    return abs(stoll(myStack.top()));
}

long long solution(string expression) {
    Expression myExpression(expression);
    vector<map<char, int>> operatorPriorities = GetOperatorsPermutation(myExpression._operatorTypes);
    long long answer = 0;

    for (const auto priority : operatorPriorities) {
        vector<string> postFix = ConvertInfixToPostFix(myExpression._splitedExpression, priority);
        long long result = Calculate(postFix);

        if (answer < result)
            answer = result;
    }

    return answer;
}