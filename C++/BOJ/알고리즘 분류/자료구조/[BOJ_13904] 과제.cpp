#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Assignment = pair<int, int>;  // <남은 일 수, 점수>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    // 1. 입력 받기
    FAST_IO
    int N, remainedDay, point;
    cin >> N;
    
    vector<Assignment> assignments(N);
    for (int i = 0; i < N; i++)
    {
        cin >> remainedDay >> point;
        assignments[i] = make_pair(remainedDay, point);
    }

    // 2. 남은 날짜를 기준으로 오름차순, 남은 날짜가 같다면 점수가 높은 순으로 정렬
    sort(assignments.begin(), assignments.end(), [](const Assignment& a1, const Assignment& a2) {
        if (a1.first == a2.first)
            return a1.second > a2.second;
        return a1.first < a2.first;
    });

    // 3. 숙제 선정하기
    priority_queue<int, vector<int>, greater<int>> completedAssignments;
    int elapsedDay = 0, index = 0;

    while (index < N)
    {
        remainedDay = assignments[index].first;
        point = assignments[index].second;

        // 기간 내에 가능한 숙제라면, 일단 클리어
        if (completedAssignments.empty() or elapsedDay < remainedDay)
        {
            completedAssignments.push(point);
            elapsedDay++;
            index++;
            continue;
        }
        
        // 기간이 지난 숙제가 클리어 했던 숙제들 중에 가장 낮은 점수보다 점수가 낮다면, 다음 숙제를 확인
        while (index < N and remainedDay <= elapsedDay and point <= completedAssignments.top())
        {
            index++;
            remainedDay = assignments[index].first;
            point = assignments[index].second;
        }

        if (index >= N)
            break;

        // 기간이 지난 숙제가 클리어 했던 숙제들 중에 가장 낮은 점수보다 점수가 높다면, 클리어 한 숙제는 버리고 해당 숙제를 클리어
        if (remainedDay <= elapsedDay and completedAssignments.top() < point)
        {
            completedAssignments.pop();
            completedAssignments.push(point);
            index++;
            continue;
        }

        completedAssignments.push(point);
        elapsedDay++;
        index++;
    }

    // 4. 클리어 한 숙제들 점수 계산 후, 출력
    int totalPoint = 0;
    while (!completedAssignments.empty())
    {
        totalPoint += completedAssignments.top();
        completedAssignments.pop();
    }

    cout << totalPoint;
    return 0;
}