#include <string>
using namespace std;

string solution(string s) {
    bool flag = false;

    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i])) {
            flag = false;
            continue;
        }

        if (!flag and isdigit(s[i])) {
            flag = true;
            continue;
        }

        else if (!flag) {
            flag = true;
            s[i] = toupper(s[i]);
            continue;
        }

        if(flag)
            s[i] = tolower(s[i]);
    }
    
    return s;
}