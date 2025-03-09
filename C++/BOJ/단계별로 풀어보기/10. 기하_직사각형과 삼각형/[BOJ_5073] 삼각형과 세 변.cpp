#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		vector<unsigned int> sideLengths;
		unsigned int sum = 0;

		for (int i = 0; i < 3; i++)
		{
			unsigned int sideLength;
			cin >> sideLength;

			sum += sideLength;
			sideLengths.push_back(sideLength);
		}

		if (sum == 0)
			break;

		sort(sideLengths.begin(), sideLengths.end());

		if (sideLengths[0] + sideLengths[1] <= sideLengths[2])
		{
			cout << "Invalid" << endl;
			continue;
		}

		int sameSideLengthCount = 0;
		unsigned int preSideLength = sideLengths[0];

		for (int i = 1; i < 3; i++)
		{
			if (preSideLength == sideLengths[i])
				sameSideLengthCount++;
			preSideLength = sideLengths[i];
		}

		switch (sameSideLengthCount)
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
		cout << endl;
	}

	return 0;
}