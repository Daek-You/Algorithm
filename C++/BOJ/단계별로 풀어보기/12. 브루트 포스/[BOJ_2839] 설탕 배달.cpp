#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int packsOf3Kilogram = N / 3;
	int packsOf5Kilogram = N / 5;
	vector<int> answers;

	for (int packOf5 = 0; packOf5 <= packsOf5Kilogram; packOf5++)
	{
		for (int packOf3 = 0; packOf3 <= packsOf3Kilogram; packOf3++)
		{
			int result = 5 * packOf5 + 3 * packOf3;
			if (result == N)
				answers.push_back(packOf3 + packOf5);
		}
	}

	sort(answers.begin(), answers.end());
	if (answers.size() == 0)
		cout << -1;
	else
		cout << answers[0];
	return 0;
}
