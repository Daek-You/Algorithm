#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<int> bookPositions(N);
    int numOfNegativePositions = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> bookPositions[i];
        if (bookPositions[i] < 0) numOfNegativePositions++;
    }

    sort(bookPositions.begin(), bookPositions.end());
    int answer = 0;

    for (int i = 0; i < numOfNegativePositions; i += M)         answer += abs(bookPositions[i]) * 2;
    for (int i = N - 1; i >= numOfNegativePositions; i -= M)    answer += bookPositions[i] * 2;

    answer -= max(abs(bookPositions.front()), abs(bookPositions.back()));
    cout << answer;
    return 0;
}