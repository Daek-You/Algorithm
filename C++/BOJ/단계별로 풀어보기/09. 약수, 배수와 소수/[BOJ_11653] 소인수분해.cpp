#include <iostream>
#include <vector>
using namespace std;

vector<int>& FactorizationInPrimeFactors(int num)
{
	vector<int>* factors = new vector<int>();
	int divideNum = 2;

	while (num / divideNum)
	{
		if (num % divideNum == 0)
		{
			factors->push_back(divideNum);
			num /= divideNum;
			continue;
		}

		divideNum++;
	}

	return *factors;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> answer = FactorizationInPrimeFactors(N);

	for (auto element : answer)
		cout << element << endl;
	
	delete answer;
	return 0;
}
