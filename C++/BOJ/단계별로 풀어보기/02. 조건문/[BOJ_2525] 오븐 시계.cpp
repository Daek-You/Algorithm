#include <iostream>
#include <string>
using namespace std;

int main() {
	int hour, minute, requestTime;
	cin >> hour >> minute;
	cin >> requestTime;

	int addHour = (minute + requestTime) / 60;
	int addMinute = (minute + requestTime) % 60;

	hour = (hour + addHour) % 24;
	minute = addMinute;
	cout << hour << ' ' << minute;
}