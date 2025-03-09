#include <iostream>
#include <queue>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

struct Truck
{
    Truck() { }
    Truck(int weight, int enterTime) : _weight(weight), _enterTime(enterTime){ }
    int _weight;
    int _enterTime;
};

void CheckTheTruckOnBridge(queue<Truck>& trucks, const int totalTime, const int bridgeLength, int& currentWeight)
{
    // 다리 위의 트럭들 중 맨 앞 트럭이 다리를 다 지났는지 체크
    while (!trucks.empty())
    {
        Truck frontTruck = trucks.front();

        // 다리를 다 건넌 경우, 총 무게에서 해당 트럭 무게 빼기
        if (totalTime - frontTruck._enterTime == bridgeLength)
        {
            currentWeight -= frontTruck._weight;
            trucks.pop();
        }

        break;
    }
}


int main()
{
    FAST_IO

    int truckNums, bridgeLength, bridgeMaxWeight;
    cin >> truckNums >> bridgeLength >> bridgeMaxWeight;

    queue<int> trucks;
    for (int i = 0; i < truckNums; i++)
    {
        int weight;
        cin >> weight;
        trucks.emplace(weight);
    }

    queue<Truck> trucksOnBridge;
    int currentWeight = 0, totalTime = 0;

    while (true)
    {
        if (trucks.empty() and trucksOnBridge.empty())
            break;

        CheckTheTruckOnBridge(trucksOnBridge, totalTime, bridgeLength, currentWeight);

        // 다리 위에 트럭을 올릴 수 있을 경우 올리기
        if (!trucks.empty() and currentWeight + trucks.front() <= bridgeMaxWeight)
        {
            int currentTruckWeight = trucks.front();
            trucksOnBridge.push(Truck(currentTruckWeight, totalTime));

            currentWeight += currentTruckWeight;
            trucks.pop();
        }

        totalTime++;
    }

    cout << totalTime;
    return 0;
}
