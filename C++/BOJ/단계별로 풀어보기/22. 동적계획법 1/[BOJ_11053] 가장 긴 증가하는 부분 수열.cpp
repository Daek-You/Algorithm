#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int GetIndexWithBinarySearch(const vector<int>& sequence, int data)
{
    if (sequence.empty())
        return 0;
    return lower_bound(sequence.begin(), sequence.end(), data) - sequence.begin();
}

int main()
{
    FAST_IO;

    int N;
    cin >> N;

    vector<int> sequence;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;

        int index = GetIndexWithBinarySearch(sequence, data);
        
        if (index < sequence.size())
            sequence[index] = data;
        else
            sequence.push_back(data);
    }

    cout << sequence.size();
    return 0;
}