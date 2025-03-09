#include <iostream>
#include <vector>
using namespace std;

bool IsPrimeNumber(unsigned int num)
{
	if (num == 0 || num == 1)
		return false;

	for (unsigned int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

vector<unsigned int>* GetPrimeNumbers(unsigned int start, unsigned int last)
{
	vector<unsigned int>* primeNumbers = new vector<unsigned int>();
	for (unsigned int i = start; i <= last; i++)
	{
		if (IsPrimeNumber(i))
			primeNumbers->push_back(i);
	}
	return primeNumbers;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned int start, last;
	cin >> start >> last;
	
	auto answers = GetPrimeNumbers(start, last);
	for (const auto answer : *answers)
		cout << answer << '\n';
	
	delete answers;
	return 0;
}