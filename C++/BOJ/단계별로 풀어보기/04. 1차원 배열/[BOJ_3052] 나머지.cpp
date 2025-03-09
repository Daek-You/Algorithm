#include <iostream>
using namespace std;

int main() {
	const int numericCount = 10;
	int modulers[42] = { 0 };
	int numeric[numericCount], cnt = 0;

	for (int i = 0; i < numericCount; i++) {
		cin >> numeric[i];

		int moduler = numeric[i] % 42;

		if (modulers[moduler] == 0)       // 기존에 없는 나머지일 때
			modulers[moduler] = 1;
		else if (modulers[moduler] == 1)  // 이미 가지고 있는 나머지일 때
			modulers[moduler] == 2;
	}

	for (int i = 0; i < 42; i++)
		if (modulers[i] == 1) // 중복이 안된 나머지들만 카운트
			cnt++;

	cout << cnt;
	return 0;
}