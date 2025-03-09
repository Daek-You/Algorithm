#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> dataArray(N);
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		dataArray[i] = data;
	}

	sort(dataArray.begin(), dataArray.end());
	for (auto result : dataArray)
		cout << result << '\n';      // endl은 시간이 오래 걸리니, '\n'을 사용하자.
	return 0;
}
