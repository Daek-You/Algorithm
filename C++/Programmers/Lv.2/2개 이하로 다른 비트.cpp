#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
const int MAX_BIT = 50;

long long Function(long long x) {
    if (x % 2 == 0)
        return x + 1;

    bitset<MAX_BIT> bits(x);
    string strBits = bits.to_string();

    for (int i = strBits.length() - 1; i >= 0; i--)
    {
        if (strBits[i] == '0') {
            strBits[i] = '1';

            if (i + 1 < strBits.length())
                strBits[i + 1] = '0';
            break;
        }
    }

    bitset<MAX_BIT> result(strBits);
    return result.to_ullong();
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size());

    for (int i = 0; i < numbers.size(); i++) {
        long long result = Function(numbers[i]);
        answer[i] = result;
    }
    return answer;
}