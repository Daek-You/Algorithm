#include <iostream>
#include <vector>
#include <stack>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    vector<int> answers(N);
    stack<int> NGEs;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!NGEs.empty() and nums[i] >= NGEs.top())
            NGEs.pop();

        if (NGEs.empty())
        {
            answers[i] = -1;
            NGEs.push(nums[i]);
            continue;
        }
        
        answers[i] = NGEs.top();
        NGEs.push(nums[i]);
    }

    for (const auto& answer : answers)
        cout << answer << " ";
    return 0;
}
