#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int dataSize;
    cin >> dataSize;
    int* dataArray = new int[dataSize];

    int minValue, maxValue;

    for (int i = 0; i < dataSize; i++)
    {
        int data;
        cin >> data;
        dataArray[i] = data;

        if (i == 0)
        {
            minValue = maxValue = data;
            continue;
        }

        minValue = std::min(minValue, dataArray[i]);
        maxValue = std::max(maxValue, dataArray[i]);
    }
    cout << minValue << " " << maxValue;
    return 0;
}