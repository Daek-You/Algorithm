#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char digitSystems[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string GetConvertedDigit(int num, int n) {
    string result;

    while (true) {
            int quotient = num / n;
            int remainder = num % n;
            result.push_back(digitSystems[remainder]);

            if (quotient == 0)
                break;
            num = quotient;
    }

    reverse(result.begin(), result.end());
    return result;
}


string solution(int n, int t, int m, int p) {
    string numbers = "";
    string answer = "";
    int currentNum = 0;
    int myTurnCount = 0;
    int myTurnIndex = p - 1;

    while (myTurnCount < t) {
        string convertedDigit = GetConvertedDigit(currentNum, n);
        numbers += convertedDigit;

        if (myTurnIndex < numbers.length()) {
            answer += numbers[myTurnIndex];
            myTurnIndex += m;
            myTurnCount++;
        }
        currentNum++;
    }


    return answer;
}