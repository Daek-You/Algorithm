#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 2000000000

int main()
{
    FAST_IO
    int N, S;
    cin >> N >> S;

    vector<int> numbers(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> numbers[i];
        numbers[i] += numbers[i - 1];
    }
    
    int left = 0, right = 1, answer = INF;
    while (left <= N)
    {
        // S 이상이 되는 구간을 찾기 위해 right를 증가
        while (right < N and numbers[right] - numbers[left] < S)
            right++;
        
        // left를 하나씩 올려가며, 가장 짧은 구간 찾기
        while (left <= right and numbers[right] - numbers[left++] >= S)
        {
            int length = right - left + 1;
            answer = min(answer, length);
        }
    }

    if (answer == INF)
        cout << "0";
    else
        cout << answer;
    return 0;
}