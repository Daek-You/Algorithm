#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> accumulatedSum(N + 1);
	cin >> accumulatedSum[1];
	
	for (int i = 2; i <= N; i++)
	{
		int number;
		cin >> number;
		accumulatedSum[i] = accumulatedSum[i - 1] + number;
	}

	for (int loop = 0; loop < M; loop++)
	{
		int i, j;
		cin >> i >> j;

		int Xj = accumulatedSum[j];
		int Xi = (i == 1) ? 0 : accumulatedSum[i - 1];

		cout << Xj - Xi << "\n";
	}

	return 0;
}