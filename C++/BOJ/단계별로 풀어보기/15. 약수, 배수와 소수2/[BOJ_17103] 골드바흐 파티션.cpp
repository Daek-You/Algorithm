#include <iostream>
#include <vector>
using namespace std;

int GetAnswer(const unsigned int& evenNum, const vector<bool>& primeNumbers)
{
	int answer = 0;
	int half = evenNum / 2;

	/// 중복을 피하기 위해, 절반만 보면 된다.
	/// 세상엔 똑똑한 사람들이 너무 많다.
	for (unsigned int i = 2; i <= half; i++)
		answer += primeNumbers[i] && primeNumbers[evenNum - i];
	return answer;
}

vector<bool>* GetPrimeNumbers(vector<bool>* primes)
{
	for (unsigned int i = 2; i * i < primes->size(); i++)
	{
		if ((*primes)[i])
		{
			for (unsigned int j = i * i; j < primes->size(); j += i)
			{
				(*primes)[j] = false;
			}
		}
	}
	return primes;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int MAX_RANGE = 1000001;
	vector<bool>* primes = new vector<bool>(MAX_RANGE, true);
	primes = GetPrimeNumbers(primes);

	int testCase;
	cin >> testCase;

	for(int i = 0; i < testCase; i++)
	{
		unsigned int n;
		cin >> n;
		cout << GetAnswer(n, *primes) << '\n';
	}

	delete primes;
	return 0;
}