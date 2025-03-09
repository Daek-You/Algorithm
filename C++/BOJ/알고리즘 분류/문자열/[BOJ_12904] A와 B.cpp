#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


bool IsAvailable(const string& source, string currentString)
{
    if (source == currentString)        return true;
    if (currentString.length() <= 1)    return false;

    if (currentString.back() == 'A')
    {
        currentString.pop_back();
        return IsAvailable(source, currentString);
    }

    currentString.pop_back();
    reverse(currentString.begin(), currentString.end());
    return IsAvailable(source, currentString);
}

int main()
{
    FAST_IO
    string source, destination;
    cin >> source >> destination;

    cout << IsAvailable(source, destination);
    return 0;
}