#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int NumOfCranes, NumOfBoxes;
vector<int> MaxLiftWeights, BoxWeights;

void Initialize()
{
    cin >> NumOfCranes;
    MaxLiftWeights.resize(NumOfCranes);
    
    for (int i = 0; i < NumOfCranes; i++)
        cin >> MaxLiftWeights[i];
    
    cin >> NumOfBoxes;
    BoxWeights.resize(NumOfBoxes);

    for (int i = 0; i < NumOfBoxes; i++)
        cin >> BoxWeights[i];
}

int Solution()
{
    if (MaxLiftWeights.front() < BoxWeights.front())
        return -1;

    int time = 0;

    while (!BoxWeights.empty())
    {
        for (int ci = 0; ci < MaxLiftWeights.size(); ci++)
        {
            for (int bi = 0; bi < BoxWeights.size(); bi++)
            {
                if (BoxWeights[bi] <= MaxLiftWeights[ci])
                {
                    BoxWeights.erase(BoxWeights.begin() + bi);
                    break;
                }
            }
        }

        time++;
    }

    return time;
}

int main()
{
    FAST_IO
    Initialize();

    sort(MaxLiftWeights.begin(), MaxLiftWeights.end(), greater<int>());
    sort(BoxWeights.begin(), BoxWeights.end(), greater<int>());

    int answer = Solution();
    cout << answer;
    return 0;

}
