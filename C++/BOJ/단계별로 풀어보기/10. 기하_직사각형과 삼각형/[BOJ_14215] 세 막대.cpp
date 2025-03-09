#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> sideLengths;
	
	for (int i = 0; i < 3; i++)
	{
		int sideLength;
		cin >> sideLength;
		sideLengths.push_back(sideLength);
	}

	sort(sideLengths.begin(), sideLengths.end());

	if (sideLengths[0] + sideLengths[1] > sideLengths[2])
		cout << sideLengths[0] + sideLengths[1] + sideLengths[2];
	else
		cout << 2 * (sideLengths[0] + sideLengths[1]) - 1;

	return 0;
}