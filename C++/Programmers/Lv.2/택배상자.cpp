#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	int deliveryBox = 1;
	stack<int> subContainer;

	for (const auto requiredOrder : order) {

                // 오더 개수 < 현재 택배 상자 번호라면, 스택에 모두 들어간 상태이므로 다 꺼내주면 된다. 
		if (order.size() < deliveryBox) {
			answer += subContainer.size();
			break;
		}

		if (deliveryBox == requiredOrder) {
			deliveryBox++;
			answer++;
			continue;
		}

		if (deliveryBox < requiredOrder) {
			while (deliveryBox < requiredOrder) subContainer.emplace(deliveryBox++);
			answer++;
			deliveryBox++;
			continue;
		}

		if (deliveryBox > requiredOrder and !subContainer.empty()) {
			if (subContainer.top() == requiredOrder) {
				answer++;
				subContainer.pop();
				continue;
			}
			break;
		}
	}

	return answer;
}