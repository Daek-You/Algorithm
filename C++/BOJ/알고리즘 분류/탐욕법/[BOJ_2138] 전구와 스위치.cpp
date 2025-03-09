#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INVALID 2000000000
#define ON   '0'
#define OFF  '1'

int N;

void OnClickSwitch(string& bulbState, int switchIndex)
{
    vector<int> targetIndexes { switchIndex - 1, switchIndex, switchIndex + 1};

    for (const int index : targetIndexes)
    {
        if (index < 0 or N <= index)
            continue;
        bulbState[index] = (bulbState[index] == ON) ? OFF : ON;
    }
}

int Solution(string source, const string& destination, bool isChangeFirstBuld)
{
    int count = 0;

    if (isChangeFirstBuld)
    {
        OnClickSwitch(source, 0);
        count++;
    }

    for (int i = 1; i < N; i++)
    {
        if (source[i - 1] != destination[i - 1])
        {
            OnClickSwitch(source, i);
            count++;
        }
    }

    return source == destination ? count : INVALID;
}

int main()
{
    FAST_IO
    cin >> N;

    string currentBulbState, targetBulbState;
    cin >> currentBulbState >> targetBulbState;

    int resultOfFirstBulbOn = Solution(currentBulbState, targetBulbState, true);
    int resultOfFirstBulbOff = Solution(currentBulbState, targetBulbState, false); 
    int answer = min(resultOfFirstBulbOn, resultOfFirstBulbOff);

    answer == INVALID ? cout << "-1" : cout << answer;
    return 0;

}
