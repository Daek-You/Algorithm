#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> sequences(N), indexes(N);
    vector<int> lis;

    for (int i = 0; i < N; i++)
    {
        cin >> sequences[i];

        if (lis.empty() or lis.back() < sequences[i])
        {
            lis.push_back(sequences[i]);
            indexes[i] = lis.size() - 1;
            continue;
        }

        int index = lower_bound(lis.begin(), lis.end(), sequences[i]) - lis.begin();
        lis[index] = sequences[i];
        indexes[i] = index;
    }

    int findIndex = lis.size() - 1;
    vector<int> answers;

    for (int i = N - 1; i >= 0; i--)
    {
        if (indexes[i] == findIndex)
        {
            findIndex--;
            answers.push_back(sequences[i]);
        }
    }

    cout << answers.size() << "\n";
    for (int i = answers.size() - 1; i >= 0; i--)
        cout << answers[i] << " ";

    return 0;
}