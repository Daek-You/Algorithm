#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> changeUnits{ 25, 10, 5, 1 };  // 100씩 곱해서 정수로 생각하자.
	int testCaseNums;
	cin >> testCaseNums;

	for (int i = 0; i < testCaseNums; i++)
	{
		int change;
		cin >> change;
		
		vector<int> answer(changeUnits.size(), 0);

		for (int i = 0; i < changeUnits.size(); i++)
		{
			answer[i] = change / changeUnits[i];
			change %= changeUnits[i];
		}

		for (const auto changeUnitNums : answer)
			cout << changeUnitNums << " ";
		cout << endl;
	}

	return 0;
}