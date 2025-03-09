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

    vector<int> positiveNumbers, negativeNumbers;
    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;

        if (number > 0) positiveNumbers.push_back(number);
        else            negativeNumbers.push_back(number);
    }

    sort(positiveNumbers.begin(), positiveNumbers.end(), greater<int>());
    sort(negativeNumbers.begin(), negativeNumbers.end());

    int answer = 0;
    int positiveSize = static_cast<int>(positiveNumbers.size());
    int negativeSize = static_cast<int>(negativeNumbers.size());

    if (positiveSize % 2 != 0)
        answer += positiveNumbers.back();
    
    for (int i = 0; i < positiveSize - 1; i += 2)
    {
        if (positiveNumbers[i + 1] == 1)        answer += positiveNumbers[i] + positiveNumbers[i + 1];
        else if (positiveNumbers[i + 1] > 0)    answer += positiveNumbers[i] * positiveNumbers[i + 1];
    }

    if (negativeSize % 2 != 0)
        answer += negativeNumbers.back();
    
    for (int i = 0; i < negativeSize - 1; i += 2)
        answer += negativeNumbers[i] * negativeNumbers[i + 1];

    cout << answer;
    return 0;
}