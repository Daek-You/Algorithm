#include <iostream>
#include <vector>
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
T GCD(const vector<T>& elements)
{
	T gcd = elements[0];
	for (int i = 1; i < elements.size(); i++)
	{
		gcd = GCD(gcd, elements[i]);
	}
	return gcd;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<unsigned long long> treeIntervals(N - 1);
	unsigned long long previousPosition;
	cin >> previousPosition;

	for (int i = 0; i < N - 1; i++)
	{
		unsigned long long position;
		cin >> position;

		treeIntervals[i] = position - previousPosition;
		previousPosition = position;
	}

	unsigned long long gcd = GCD(treeIntervals);
	int answer = 0;
	for (const auto interval : treeIntervals)
	{
		answer += (interval - gcd) / gcd;
	}

	cout << answer;
	return 0;
}