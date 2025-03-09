#include <iostream>
#include <string>
using namespace std;

int main() {
	int hour, minute;
	cin >> hour >> minute;

	int temp = minute - 45;

	if (temp < 0)
	{
		hour -= 1;
		minute = 60 + temp;

		if (hour < 0)
			hour = 23;
	}
	else
		minute = temp;

	cout << hour << ' ' << minute;
}