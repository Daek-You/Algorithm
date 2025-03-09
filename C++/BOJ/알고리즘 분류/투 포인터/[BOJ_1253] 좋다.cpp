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

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int left = 0, right = N - 1;
        int target = numbers[i];

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            if (left == i)
            {
                left++;
                continue;
            }

            if (right == i)
            {
                right--;
                continue;
            }

            if (sum == target)
            {
                answer++;
                break;
            }

            if (sum < target) left++;
            else              right--;
        }
    }

    cout << answer;
    return 0;
}