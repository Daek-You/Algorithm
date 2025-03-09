#include <iostream>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int answer = 0;
	cin >> N;

	for (int i = 1; i * i <= N; i++)
		answer++;
	
	cout << answer;
	return 0;
}