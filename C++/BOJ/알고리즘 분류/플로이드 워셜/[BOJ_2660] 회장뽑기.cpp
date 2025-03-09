#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INFINITY 1000000000

void FloydWarshall(vector<vector<int>>& friendTable, int memberCount)
{
    for (int mid = 1; mid <= memberCount; mid++)
        for (int from = 1; from <= memberCount; from++)
            for (int to = 1; to <= memberCount; to++)
                friendTable[from][to] = min(friendTable[from][to], friendTable[from][mid] + friendTable[mid][to]);
}

int main()
{
    FAST_IO
    int memberCount;
    cin >> memberCount;

    // 1. 초기화
    vector<vector<int>> friendTable(memberCount + 1, vector<int>(memberCount + 1, INFINITY));
    while (true)
    {
        int memberId1, memberId2;
        cin >> memberId1 >> memberId2;

        if (memberId1 == -1 and memberId2 == -1)
            break;
        
        friendTable[memberId1][memberId2] = 1;
        friendTable[memberId2][memberId1] = 1;
    }

    // 자기 자신은 0으로 초기화
    for (int i = 1; i <= memberCount; i++)
        friendTable[i][i] = 0;

    // 2. 플로이드 워셜 알고리즘
    FloydWarshall(friendTable, memberCount);
    int answerPoint = INFINITY;
    vector<int> answers;

    for (int i = 1; i <= memberCount; i++)
    {
        int point = 0;
        for (int j = 1; j <= memberCount; j++)
            point = max(point, friendTable[i][j]);
        
        if (point < answerPoint)
        {
            answerPoint = point;
            answers.clear();
            answers.push_back(i);
        }
        else if (point == answerPoint)
            answers.push_back(i);
    }

    cout << answerPoint << " " << answers.size() << "\n";
    for (const int& answer : answers)
        cout << answer << " ";
    return 0;
}