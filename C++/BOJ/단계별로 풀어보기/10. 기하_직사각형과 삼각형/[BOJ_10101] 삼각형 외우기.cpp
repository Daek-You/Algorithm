#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<unsigned int> angles;

	for (int i = 0; i < 3; i++)
	{
		unsigned int angle;
		cin >> angle;
		angles.push_back(angle);
	}

	unsigned int sum = 0;
	for (const auto angle : angles)
		sum += angle;

	if (sum != 180)
	{
		cout << "Error";
		return 0;
	}

	sort(angles.begin(), angles.end());
	
	unsigned int preValue = angles[0];
	int sameAngleCount = 0;

	for (int i = 1; i < 3; i++)
	{
		if (preValue == angles[i])
			sameAngleCount++;
		preValue = angles[i];
	}

	switch (sameAngleCount)
	{
	case 0:
		cout << "Scalene";
		break;
	case 1:
		cout << "Isosceles";
		break;
	case 2:
		cout << "Equilateral";
		break;
	}

	return 0;
}