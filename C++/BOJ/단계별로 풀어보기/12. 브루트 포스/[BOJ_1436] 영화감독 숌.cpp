#include <iostream>
#include <string>
using namespace std;


bool IsEndNumber(const string& num)
{
	int continuousSixCount = 0;

	for (const auto numeric : num)
	{
		if (numeric != '6')
		{
			continuousSixCount = 0;
			continue;
		}

		continuousSixCount++;
		if (continuousSixCount == 3)
			break;
	}

	return continuousSixCount == 3;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	long long targetNum = 666;
	int currentIdx = 0;

	while (true)
	{
		string num(to_string(targetNum));
		if (IsEndNumber(num))
			currentIdx++;

		if (currentIdx == N)
		{
			cout << num;
			break;
		}

		targetNum++;
	}

	return 0;
}
