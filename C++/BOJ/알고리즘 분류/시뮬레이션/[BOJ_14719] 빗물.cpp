#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int height, width;
    cin >> height >> width;

    vector<int> blockHeights(width);
    for (int i = 0; i < width; i++)     cin >> blockHeights[i];

    int answer = 0;

    for (int current = 1; current < width; current++)
    {
        int leftMaxHeight = 0, rightMaxHeight = 0;

        for (int left = 0; left < current; left++)              leftMaxHeight  = max(leftMaxHeight, blockHeights[left]);
        for (int right = current + 1; right < width; right++)   rightMaxHeight = max(rightMaxHeight, blockHeights[right]);

        int waterAmount = min(leftMaxHeight, rightMaxHeight) - blockHeights[current];
        answer += max(0, waterAmount);
    }

    cout << answer;
    return 0;
}
