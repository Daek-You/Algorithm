#include <vector>
#include <stack>
using namespace std;

void Deliver(const int cap, stack<int>& house) {
    int box = 0;
    while (!house.empty() and box <= cap) {
        int& delivery = house.top();

        if (delivery + box <= cap) {
            box += delivery;
            delivery = 0;
            house.pop();
            continue;
        }

        delivery -= (cap - box);
        break;
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> deliveryHouses;
    stack<int> pickUpHouses;

    // 택배 배달할 집과 수거해 올 집 스택에 저장하기
    for (int i = 0; i < n; i++) {
        deliveryHouses.emplace(deliveries[i]);
        pickUpHouses.emplace(pickups[i]);
    }

    while (!(deliveryHouses.empty() and pickUpHouses.empty())) {

        // 배달하거나 수거할 필요 없는 집들은 스택에서 제외 시키기
        while (!deliveryHouses.empty() and deliveryHouses.top() == 0)
            deliveryHouses.pop();
        while (!pickUpHouses.empty() and pickUpHouses.top() == 0)
            pickUpHouses.pop();

        answer += max(deliveryHouses.size() * 2, pickUpHouses.size() * 2);

        // 택배 배달
        Deliver(cap, deliveryHouses);

        // 재활용품 수거
        Deliver(cap, pickUpHouses);
    }

    return answer;
}