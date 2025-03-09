#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> dataArray(10001, 0);
	int maxNum = 0;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		dataArray[data]++;
		maxNum = max(maxNum, data);
	}

	for (int i = 1; i < dataArray.size(); i++)
	{
		if (i > maxNum)
			break;

		for (int j = 0; j < dataArray[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}
