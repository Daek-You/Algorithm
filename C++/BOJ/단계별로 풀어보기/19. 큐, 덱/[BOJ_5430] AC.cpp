#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

void Print(const deque<int>& array, bool isValidOperation, bool isReversed)
{
	if (!isValidOperation)
	{
		cout << "error" << '\n';
		return;
	}

	cout << '[';

	if (isReversed)
	{
		for (int i = array.size() - 1; i >= 0; i--)
		{
			cout << array[i];

			if (i != 0)
				cout << ',';
		}
	}

	else
	{
		for (int i = 0; i < array.size(); i++)
		{
			cout << array[i];

			if (i != array.size() - 1)
				cout << ',';
		}
	}

	cout << ']' << '\n';
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		string operations;
		cin >> operations;

		int arrayLength;
		cin >> arrayLength;

		string inputArray;
		cin >> inputArray;

		deque<int> myDataArray;
		string data = "";
		int currentDataCount = 0;

		for (int i = 1; i < inputArray.length() && currentDataCount != arrayLength; i++)        // 데이터 추출 과정
		{
			if ((inputArray[i] == ',') or (inputArray[i] == ']'))
			{
				myDataArray.push_back(stoi(data));
				currentDataCount++;
				data.clear();
				continue;
			}
			data.push_back(inputArray[i]);
		}

		bool isValidOperation = true;
		bool isReversed = false;

		for (const auto& operation : operations)
		{
			if (operation == 'R')
				isReversed = !isReversed;

			else if (operation == 'D')
			{
				if (myDataArray.empty())
				{
					isValidOperation = false;
					break;
				}

				isReversed ? myDataArray.pop_back() : myDataArray.pop_front();
			}
		}

		Print(myDataArray, isValidOperation, isReversed);
	}

	return 0;
}