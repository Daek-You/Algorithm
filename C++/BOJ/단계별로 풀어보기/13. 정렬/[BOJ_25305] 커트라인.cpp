#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, k;
	cin >> N >> k;

	vector<int> dataArray(N);
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		dataArray[i] = data;
	}

	sort(dataArray.begin(), dataArray.end(), greater<int>());  // 내림차순
	cout << dataArray[k - 1];
	return 0;
}
