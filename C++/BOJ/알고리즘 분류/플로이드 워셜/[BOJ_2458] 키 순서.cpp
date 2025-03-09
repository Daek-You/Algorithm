#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    // 1. 입력 초기화
    vector<vector<bool>> heightTable(N + 1, vector<bool>(N + 1, false));    // heightTable[i][j] = true -> "i가 j보다 크다"
    int shorter, taller;

    for (int i = 0; i < M; i++)
    {
        cin >> shorter >> taller;
        heightTable[taller][shorter] = true;
    }

    // 2. Floyd-Warshall Algorithm
    for (int mid = 1; mid <= N; mid++)
        for (int from = 1; from <= N; from++)
            for (int to = 1; to <= N; to++)
                if (heightTable[from][mid] and heightTable[mid][to])
                    heightTable[from][to] = true;

    // 3. 순위가 확정 가능한 사람 수 세기
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        for (int j = 1; j <= N; j++)
        {
            if (heightTable[i][j] or heightTable[j][i])
                count++;
        }

        if (count == N - 1)
            answer++;
    }

    cout << answer;
    return 0;
}