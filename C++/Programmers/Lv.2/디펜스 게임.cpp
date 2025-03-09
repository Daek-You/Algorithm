#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	priority_queue<int> enemies;
	int i = 0;

	for (; i < enemy.size(); i++) {
		if (n < enemy[i] and k == 0)
			break;

		enemies.emplace(enemy[i]);
		n -= enemy[i];
		answer++;

		while (!enemies.empty() and n < 0) {
			if ((k == 0 and n < 0)) {
				answer--;
				break;
			}

			n += enemies.top();
			enemies.pop();
			k--;
		}
	}

	return i == enemy.size() ? enemy.size() : answer;
}