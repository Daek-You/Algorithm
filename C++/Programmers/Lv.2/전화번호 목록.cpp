#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPrefix(const string& shortStr, const string& longStr) {
    return shortStr == longStr.substr(0, shortStr.size());
}

bool solution(vector<string> phone_book) {
    if (phone_book.size() == 1)
        return true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (IsPrefix(phone_book[i], phone_book[i + 1]))
            return false;
    }

    return true;
}