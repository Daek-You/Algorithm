#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 1000000

vector<bool> Buttons(10, true);  // true: 사용 가능, false: 고장

bool CanMove(int channel)
{
    if (channel == 0)
        return Buttons[0];
    
    while (channel)
    {
        if (!Buttons[channel % 10]) return false;
        channel /= 10;
    }

    return true;
}

int main()
{
    FAST_IO
    int targetChannel, numOfBrokenButtons, brokenButton;
    cin >> targetChannel >> numOfBrokenButtons;

    for (int i = 0; i < numOfBrokenButtons; i++)
    {
        cin >> brokenButton;
        Buttons[brokenButton] = false;
    }

    int answer = abs(targetChannel - 100);  // '+', '-'만 사용하여 채널 이동한 경우

    for (int i = 0; i < MAX; i++)
    {
        if (CanMove(i))
        {
            int numOfOperations = to_string(i).length() + abs(i - targetChannel);
            answer = min(answer, numOfOperations);
        }
    }

    cout << answer;
    return 0;
}
