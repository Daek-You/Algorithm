#include <iostream>
using namespace std;

int main() {
	int diceTable[7] = { 0 };
	int result;

	for (int i = 0; i < 3; i++)
	{
		cin >> result;
		diceTable[result]++;
	}

	int howManyEquals = 0;
	int targetNum = 0;

	for (int i = 1; i < 7; i++)
	{
		if (diceTable[i] == 3)
		{
			howManyEquals = 3;
			targetNum = i;
			break;
		}

		else if (diceTable[i] == 2)
		{
			howManyEquals = 2;
			targetNum = i;
			break;
		}

		else if (diceTable[i] == 1)
		{
			howManyEquals = 1;
			targetNum = i;
		}
	}

	switch (howManyEquals)
	{
	case 3:
		cout << 10000 + targetNum * 1000;
		break;
	case 2:
		cout << 1000 + targetNum * 100;
		break;
	case 1:
		cout << targetNum * 100;
	}
}