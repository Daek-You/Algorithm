#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dataNums;
	cin >> dataNums;

	vector<int> dataArray(dataNums);
	for (int i = 0; i < dataNums; i++)
	{
		int data;
		cin >> data;
		dataArray[i] = data;
	}

	sort(dataArray.begin(), dataArray.end());
	for (const auto result : dataArray)
		cout << result << endl;
	return 0;
}
