#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int maxValue = -1;
	int row = -1, column = -1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int data;
			cin >> data;

			if (maxValue < data)
			{
				maxValue = data;
				row = i + 1;
				column = j + 1;
			}
		}
	}

	cout << maxValue << endl;
	cout << row << " " << column;
	return 0;
}