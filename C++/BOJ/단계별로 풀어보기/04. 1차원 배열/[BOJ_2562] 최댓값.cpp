#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int maxValue, index;
    for (int i = 0; i < 9; i++)
    {
        int data;
        cin >> data;

        if (i == 0)
        {
            maxValue = data;
            index = i + 1;
            continue;
        }

        if (data > maxValue)
        {
            maxValue = data;
            index = i + 1;
        }
    }

    cout << maxValue << " " << index;

    return 0;
}