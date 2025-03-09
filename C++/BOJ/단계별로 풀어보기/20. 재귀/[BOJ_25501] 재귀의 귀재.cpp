#include <iostream>
#include <string>
using namespace std;

bool Recursion(const string& content, int left, int right, int& callCount)
{
	if (left >= right) return true;
	else if (content[left] != content[right]) return false;
	else return Recursion(content, left + 1, right - 1, ++callCount);
}

bool IsPalindrome(const string& content, int& callCount)
{
	return Recursion(content, 0, content.length() - 1, ++callCount);
}


int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int recusuionCallCount = 0;
		string content;
		cin >> content;

		bool returnValue = IsPalindrome(content, recusuionCallCount);
		cout << returnValue << " " << recusuionCallCount << "\n";
	}

	return 0;
}