#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string RemoveZero(const string& str, int& removedZeroCount) {
    string result;

    for (const auto element : str) {
        if (element == '1') {
            result.push_back('1');
            continue;
        }

        removedZeroCount++;
    }
    return result;
}

string ConvertBinary(const string& oneBinary) {
    string result;
    int targetNum = oneBinary.length();

    while (true) {
        int remainder = targetNum % 2;
        targetNum /= 2;

        char numericChar = remainder + '0';
        result.push_back(numericChar);

        if (targetNum == 0)
            break;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool IsCanBinaryConverting(const string& str) {
    return str.length() > 1;
}

vector<int> solution(string s) {
    int removedZeroCount = 0;
    int binaryConvertingCount = 0;
    string temp = s;

    while (true) {
        binaryConvertingCount++;
        string removedZero = RemoveZero(temp, removedZeroCount);

        if (IsCanBinaryConverting(removedZero)) {
            temp = ConvertBinary(removedZero);
            continue;
        }

        break;
    }

    vector<int> answer {binaryConvertingCount, removedZeroCount};
    return answer;
}
