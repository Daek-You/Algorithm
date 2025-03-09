#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string str;
    cin >> str;

    vector<string> answers;
    for (int i = 0; i < str.length(); i++)
        answers.push_back(str.substr(i));
    
    sort(answers.begin(), answers.end());
    for (const string& answer : answers)
        cout << answer << "\n";
    return 0;
}