#include <iostream>
using namespace std;

int main()
{
	int byteSize;
	cin >> byteSize;
	
	int loopCount = byteSize / 4;

	for (int i = 0; i < loopCount; i++)
	{
		cout << "long" << " ";
	}
	cout << "int";
}