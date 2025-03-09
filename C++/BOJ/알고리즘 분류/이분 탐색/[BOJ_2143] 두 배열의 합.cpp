#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int T, N, M;
    cin >> T >> N;

    // 1. A, B 입력 받기
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    // 2. A 배열의 모든 누적합 경우의 수를 저장
    vector<int> accumulatedSetOfA;
    for (int i = 0; i < N; i++)
    {
        int sum = A[i];
        accumulatedSetOfA.push_back(sum);

        for (int j = i + 1; j < N; j++)
        {
            sum += A[j];
            accumulatedSetOfA.push_back(sum);
        }
    }

    // 3. B 배열의 모든 누적합 경우의 수를 저장
    vector<int> accumulatedSetOfB;
    for (int i = 0; i < M; i++)
    {
        int sum = B[i];
        accumulatedSetOfB.push_back(sum);

        for (int j = i + 1; j < M; j++)
        {
            sum += B[j];
            accumulatedSetOfB.push_back(sum);
        }
    }

    // 4. B 누적합 경우의 수 배열을 정렬 후, 이진 탐색
    sort(accumulatedSetOfB.begin(), accumulatedSetOfB.end());
    long long answer = 0;

    for (int i = 0; i < accumulatedSetOfA.size(); i++)
    {
        long long value = T - accumulatedSetOfA[i];
        long long left = lower_bound(accumulatedSetOfB.begin(), accumulatedSetOfB.end(), value) - accumulatedSetOfB.begin();
        long long right = upper_bound(accumulatedSetOfB.begin(), accumulatedSetOfB.end(), value) - accumulatedSetOfB.begin();

        answer += (right - left);
    }

    cout << answer;
    return 0;
}