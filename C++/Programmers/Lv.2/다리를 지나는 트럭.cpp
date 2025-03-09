#include <vector>
#include <queue>
using namespace std;

struct Truck
{
	Truck(int enterTime, int weight) : _enterTime(enterTime), _weight(weight) { }
	int _enterTime;
	int _weight;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int elapsedTime = 1;
	int weightSum = 0;
	queue<Truck> trucksOnBridge;

	for (int i = 0; i < truck_weights.size(); i++) {
		int truckWeight = truck_weights[i];

        // 1. 다리 위에 트럭이 없거나, 트럭을 더 올릴 수 있으면 올리기
		if ((trucksOnBridge.empty()) or (weightSum + truckWeight <= weight)) {
			trucksOnBridge.emplace(elapsedTime++, truckWeight);
			weightSum += truckWeight;
			continue;
		}

        // 2. 다리 위의 맨 앞 트럭의 도착 시간 계산하여 "경과 시간(elapsedTime)" 갱신하기
		Truck frontTruck = trucksOnBridge.front();
		trucksOnBridge.pop();
		elapsedTime = max(frontTruck._enterTime + bridge_length, elapsedTime);
		weightSum -= frontTruck._weight;

        
        // 3. 다리에 다음 트럭을 실었을 때 최대 하중을 넘으면, 현재 루프를 다시 반복하여 2번 실행하게 만들기
		bool isOverWeight = weight < (weightSum + truckWeight);
		if (isOverWeight) {
			i -= 1;
			continue;
		}

        // 4. 다리 위 맨 앞 트럭을 도착 지점에 보냈다면, 새로 실을 트럭을 다리 위에 올리기
		trucksOnBridge.emplace(elapsedTime, truckWeight);
		weightSum += truckWeight;
		elapsedTime++;
	}

        // 5. 다리 위에 남아 있는 트럭들의 도착 시간 계산하기
	while (!trucksOnBridge.empty()) {
		Truck truck = trucksOnBridge.front();
		trucksOnBridge.pop();
		elapsedTime = truck._enterTime + bridge_length;
	}

	return elapsedTime;
}