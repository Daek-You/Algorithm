#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using uint32 = unsigned int;

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

struct Tower
{
    Tower() { }
    Tower(uint32 i, uint32 h) : index(i), height(h) { }
    uint32 index, height;
};

int main()
{
    FAST_IO
    uint32 N, currentTowerHeight;
    cin >> N;

    stack<Tower> towers;
    vector<uint32> answers(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> currentTowerHeight;

        if (towers.empty())
        {
            towers.emplace(Tower(i + 1, currentTowerHeight));
            continue;
        }

        while (!towers.empty() and towers.top().height < currentTowerHeight)
            towers.pop();

        if (!towers.empty())
            answers[i] = towers.top().index;
        towers.emplace(Tower(i + 1, currentTowerHeight));
    }

    for (const uint32& answer : answers)
        cout << answer << " ";
    return 0;
}