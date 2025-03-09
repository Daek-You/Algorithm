#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<int> Parents, Heights;

int Find(int point)
{
    if (point == Parents[point])
        return point;
    return Parents[point] = Find(Parents[point]);
}

bool GetResultOfTryingUnion(int point1, int point2) // 사이클이 있을 시 false 리턴
{
    int x = Find(point1), y = Find(point2);
    if (x == y)
        return false;
    
    // 두 집합 트리의 높이가 같으면, y 집합을 그냥 x 집합 하위로 넣자.
    if (Heights[x] == Heights[y])
    {
        Parents[y] = x;
        Heights[x] += 1;
    }
    // 높이가 작은 집합을 하위로 넣어야 트리의 깊이가 안 깊어진다.
    else if (Heights[x] < Heights[y])
        Parents[x] = y;
    else
        Parents[y] = x;
    return true;
}

int main()
{
    FAST_IO
    int numOfPoints, numOfTurns;
    cin >> numOfPoints >> numOfTurns;

    Parents.resize(numOfPoints);
    Heights.resize(numOfPoints, 1);
    for (int i = 0; i < numOfPoints; i++)
        Parents[i] = i;

    int turn = 1;
    for (; turn <= numOfTurns; turn++)
    {
        int point1, point2;
        cin >> point1 >> point2;

        if (!GetResultOfTryingUnion(point1, point2))
        {
            cout << turn;
            break;
        }
    }

    if (turn > numOfTurns)
        cout << "0";
    return 0;
}