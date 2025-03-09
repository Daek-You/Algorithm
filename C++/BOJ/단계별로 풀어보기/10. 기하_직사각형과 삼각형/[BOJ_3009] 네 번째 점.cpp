#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<int, int> xPos;
	map<int, int> yPos;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;

		auto xPosIt = xPos.find(x);
		auto yPosIt = yPos.find(y);

		if (xPosIt == xPos.end())
			xPos.insert(make_pair(x, 0));
		if (yPosIt == yPos.end())
			yPos.insert(make_pair(y, 0));

		xPos[x] += 1;
		yPos[y] += 1;
	}

	for (const auto xElement : xPos)
	{
		if (xElement.second < 2)
		{
			cout << xElement.first << " ";
			break;
		}
	}

	for (const auto yElement : yPos)
	{
		if (yElement.second < 2)
		{
			cout << yElement.first;
			break;
		}
	}

	return 0;
}