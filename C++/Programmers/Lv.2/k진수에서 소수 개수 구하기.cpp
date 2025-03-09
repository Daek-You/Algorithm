#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string GetKNumber(int n, int k) {
    string number;

    while (true) {
        int quotient = n / k;
        int remainder = n % k;
        number.push_back(remainder + '0');
        
        if (quotient == 0)
            break;
        n = quotient;
    }

    reverse(number.begin(), number.end());
    return number;
}

bool IsPrimeNumber(long long n) {
    if (n == 1)
        return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int solution(int n, int k) {
    int answer = 0;
    string kNum = GetKNumber(n, k);
    stringstream tokenizer(kNum);
    string num;

    while (getline(tokenizer, num, '0')) {
        if (!num.empty())
            answer += IsPrimeNumber(stoll(num));
    }

    return answer;
}