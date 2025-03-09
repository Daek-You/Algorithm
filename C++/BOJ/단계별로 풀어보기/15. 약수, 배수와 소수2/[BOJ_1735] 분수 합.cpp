#include <iostream>
using namespace std;

template<typename T>
T GCD(T x, T y)
{
	if (y == 0)
		return x;

	T moduler = 0;
	while (x % y != 0)
	{
		moduler = x % y;
		x = y;
		y = moduler;
	}
	return y;
}

template<typename T>
pair<T, T> AddFountain(T numer1, T denom1, T numer2, T denom2)
{
	T denominator = denom1 * denom2;
	T numerator = numer1 * denom2 + numer2 * denom1;
	return pair<T, T>(numerator, denominator);
}

template<typename T>
pair<T, T> GetIrreducibleFraction(pair<T, T>& fountain)
{
	int gcd = GCD(fountain.first, fountain.second);
	return pair<T, T>(fountain.first / gcd, fountain.second / gcd);
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int denominator1, denominator2, numerator1, numerator2;
	cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;

	auto fountain = AddFountain(numerator1, denominator1, numerator2, denominator2);
	auto irreducibleFraction = GetIrreducibleFraction(fountain);

	cout << irreducibleFraction.first << ' ' << irreducibleFraction.second;
	return 0;
}