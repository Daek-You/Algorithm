#include <iostream>
#include <vector>
using namespace std;

void Backtracking(vector<int>& weights, int& maxEnegy, int sum)
{
    if (weights.size() == 2)
    {
        maxEnegy = max(maxEnegy, sum);
        return;
    }

    for (int i = 1; i < weights.size() - 1; i++)
    {
        int element = weights[i];
        int addValue = weights[i - 1] * weights[i + 1];

        weights.erase(weights.begin() + i);
        Backtracking(weights, maxEnegy, sum + addValue);
        weights.emplace(weights.begin() + i, element);
    }
}

int GetMaxEnegy(vector<int>& weights)
{
    int answer = -1;
    Backtracking(weights, answer, 0);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; i++)
        cin >> weights[i];

    int answer = GetMaxEnegy(weights);
    cout << answer;
    return 0;
}