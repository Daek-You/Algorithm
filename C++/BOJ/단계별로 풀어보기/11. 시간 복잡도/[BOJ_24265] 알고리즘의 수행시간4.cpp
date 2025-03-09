#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;

	long long operationNums = 0;

	for (int i = 1; i < N; i++)
		operationNums += i;

	cout << operationNums << endl;
	cout << 2;
	return 0;
}