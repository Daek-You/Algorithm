#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned int N;
	cin >> N;

	string strNum(to_string(N));
	sort(strNum.begin(), strNum.end(), greater<unsigned int>());

	for (const auto result : strNum)
		cout << result;
	return 0;
}
