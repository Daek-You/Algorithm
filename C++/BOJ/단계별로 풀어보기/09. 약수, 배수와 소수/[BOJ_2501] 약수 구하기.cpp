#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> divisors;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			divisors.push_back(i);

			if (N / i != i)
				divisors.push_back(N / i);
		}
	}

	sort(divisors.begin(), divisors.end());

	if (divisors.size() < K)
		cout << "0";
	else
		cout << divisors[K - 1];

	return 0;
}