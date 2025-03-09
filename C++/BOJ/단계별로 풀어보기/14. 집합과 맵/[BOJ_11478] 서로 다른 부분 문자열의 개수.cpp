#include <iostream>
#include <set>
using namespace std;

/*  subset으로 인해, 메모리를 너무나 잡아먹는 비효율적인 풀이다.
*  라고 생각했는데, 이게 메모리 더 적게 먹네?,,
void RegacySolve()
{
	string input;
	cin >> input;

	unordered_set<string> sets;
	for (int subsetNum = 1; subsetNum <= input.length(); subsetNum++)
	{
		for (int i = 0; i < input.length(); i++)
		{
			string target = input.substr(i, subsetNum);
			sets.insert(target);
		}
	}

	cout << sets.size();
}
*/

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	set<string> _set;
	string temp;
	for (int i = 0; i < input.length(); ++i)
	{
		temp = "";
		for (int j = i; j < input.length(); ++j)
		{
			temp += input[j];
			_set.insert(temp);
		}
	}

	cout << _set.size();
	return 0;
}