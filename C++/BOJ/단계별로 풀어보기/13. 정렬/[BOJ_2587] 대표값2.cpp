#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	vector<int> dataArray(5);
	for (int i = 0; i < dataArray.size(); i++)
	{
		int data;
		cin >> data;
		dataArray[i] = data;
	}

	sort(dataArray.begin(), dataArray.end());
	float mean = accumulate(dataArray.begin(), dataArray.end(), 0) / dataArray.size();
	int median = dataArray[dataArray.size() / 2];

	cout << mean << '\n' << median;
	return 0;
}
