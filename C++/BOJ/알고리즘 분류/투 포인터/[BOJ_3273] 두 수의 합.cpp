#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int FindTuple(const vector<int>& sequences, const int targetNumber)
{
    int start = 0, end = sequences.size() - 1, tuples = 0;

    while (start < end)
    {
        int sum = sequences[start] + sequences[end];

        if (targetNumber < sum)
            end--;
        else if (sum < targetNumber)
            start++;
        else
        {
            tuples++;
            start++;
            end--;
        }
    }

    return tuples;
}

int main()
{
    FAST_IO
    int N, targetNumber;
    cin >> N;

    vector<int> sequences(N);
    for (int i = 0; i < N; i++)
        cin >> sequences[i];

    sort(sequences.begin(), sequences.end());
    cin >> targetNumber;

    int answer = FindTuple(sequences, targetNumber);
    cout << answer;
    return 0;
}