#include <string>
#include <sstream>
using namespace std;
const int MIN_IDX = 0;
const int MAX_IDX = 1;

string solution(string s) {
    istringstream iss(s);
    string buffer;
    long long numbers[2] = { 0, };
    bool isInit = true;

    while (getline(iss, buffer, ' ')) {
        if (isInit) {
            numbers[MIN_IDX] = numbers[MAX_IDX] = stoll(buffer);
            isInit = false;
            continue;
        }

        long long num = stoll(buffer);
        if (num < numbers[MIN_IDX])
            numbers[MIN_IDX] = num;
        if (num > numbers[MAX_IDX])
            numbers[MAX_IDX] = num;
    }

    string answer;
    for (int i = 0; i < 2; i++) {
        string num = to_string(numbers[i]);
        
        if (i == 1)
            answer.push_back(' ');
        answer += num;
    }

    return answer;
}