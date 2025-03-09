#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> pieces{ 1, 1, 2, 2, 2, 8 };
	
	for (int i = 0; i < 6; i++)
	{
		int piece;
		cin >> piece;

		int difference = pieces[i] - piece;
		cout << difference << " ";
	}
	return 0;
}