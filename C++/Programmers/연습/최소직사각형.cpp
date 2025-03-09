#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes)
{
    int walletWidth = 0, walletHeight = 0;

    for (const vector<int>& size : sizes)
    {
        bool longerIndex = (size[0] > size[1]) ? 0 : 1;
        int width = size[longerIndex], height = size[!longerIndex];

        walletWidth = max(walletWidth, width);
        walletHeight = max(walletHeight, height);
    }

    return walletWidth * walletHeight;
}