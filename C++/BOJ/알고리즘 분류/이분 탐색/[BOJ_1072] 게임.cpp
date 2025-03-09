#include <iostream>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

long long Solution(const long long numOfTotalGamePlays, const long long numOfWins, const long long originalWinningRate)
{
    long long left = 1, right = 1000000000;
    long long additionalGamePlays = -1;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long gamePlays = numOfTotalGamePlays + mid;
        long long wins = numOfWins + mid;

        long long newWinningRate = (100 * wins) / gamePlays;

        if (newWinningRate > originalWinningRate)
        {
            additionalGamePlays = mid;
            right = mid - 1;
            continue;
        }

        left = mid + 1;
    }

    return additionalGamePlays;
}

int main()
{
    FAST_IO
    long long numOfTotalGamePlays, numOfWins;
    cin >> numOfTotalGamePlays >> numOfWins;

    long long winningRate = (100 * numOfWins) / numOfTotalGamePlays;
    if (winningRate >= 99)
    {
        cout << "-1";
        return 0;
    }

    long long answer = Solution(numOfTotalGamePlays, numOfWins, winningRate);
    cout << answer;
    return 0;
}