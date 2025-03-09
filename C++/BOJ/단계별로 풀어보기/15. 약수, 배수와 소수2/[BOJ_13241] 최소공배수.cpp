#include <iostream>
using namespace std;

template<typename T>
void Swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

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
T LCM(T x, T y)
{
	return (x * y) / GCD(x, y);
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	cout << LCM(a, b);
	return 0;
}