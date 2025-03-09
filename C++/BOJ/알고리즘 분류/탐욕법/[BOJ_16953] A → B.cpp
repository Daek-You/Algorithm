#include <iostream>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

long long TraceInReverse(string destination, const string& source)
{
    long long operationCount = 0;

    while (!destination.empty())
    {
        if (destination == source)
            return operationCount + 1;
        
        long long number = stoll(destination);

        if (number % 2 == 0)
        {
            destination = to_string(number / 2);
            operationCount++;
        }

        else if (number % 2 != 0 and destination.back() == '1')
        {
            destination.pop_back();
            operationCount++;
        }

        else
            break;
    }

    return -1;
}

int main()
{
    FAST_IO
    string source, destination;
    cin >> source >> destination;

    long long answer = TraceInReverse(destination, source);
    cout << answer;
    return 0;

}
