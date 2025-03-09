#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string buffer;

	while(true)
	{
		getline(cin, buffer);

		if (buffer.empty())
			break;
		cout << buffer << endl;
	}

	return 0;
}