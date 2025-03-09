#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	long long totalPrice;
	int kindOfgoods, price, nums;
	cin >> totalPrice;
	cin >> kindOfgoods;

	long long checkPrice = 0;
	for (int i = 0; i < kindOfgoods; i++)
	{
		cin >> price >> nums;
		checkPrice += (price * nums);
	}

	string answer = (totalPrice == checkPrice) ? "Yes" : "No";
	cout << answer;
}