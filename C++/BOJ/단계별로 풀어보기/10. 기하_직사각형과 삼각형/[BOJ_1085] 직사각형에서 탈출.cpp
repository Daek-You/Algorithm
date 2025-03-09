#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int widthDiffernce = min(x, w - x);
	int heightDiffernce = min(y, h - y);

	cout << min(widthDiffernce, heightDiffernce);
	return 0;
}