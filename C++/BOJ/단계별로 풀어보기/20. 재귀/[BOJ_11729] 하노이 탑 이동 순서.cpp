#include <iostream>
using namespace std;

void HanoiTower(int disk, int from, int by, int to)
{
    if (disk == 1)
    {
        cout << from << " " << to << '\n';
        return;
    }
    
    HanoiTower(disk - 1, from, to, by);
    cout << from << " " << to << '\n';
    HanoiTower(disk - 1, by, from, to);
}

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int minCount = (1 << N) - 1;
    cout << minCount << '\n';
    HanoiTower(N, 1, 2, 3);
    return 0;
}
