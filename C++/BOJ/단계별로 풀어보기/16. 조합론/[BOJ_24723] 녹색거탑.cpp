#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << static_cast<int>(pow(2, N));
	return 0;
}