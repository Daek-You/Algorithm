#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void AddElement(set<int>& set, int n)
{
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		set.insert(data);
	}
}

int GetAnswer(set<int>& set1, set<int>& set2)
{
	vector<int> A_diff_B(set1.size() + set2.size());
	vector<int> B_diff_A(set1.size() + set2.size());
	
	auto lastIter1 = set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), A_diff_B.begin());
	auto lastIter2 = set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), B_diff_A.begin());

	A_diff_B.erase(lastIter1, A_diff_B.end());
	B_diff_A.erase(lastIter2, B_diff_A.end());

	return A_diff_B.size() + B_diff_A.size();
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A_nums, B_nums;
	cin >> A_nums >> B_nums;

	set<int> set1, set2;
	AddElement(set1, A_nums);
	AddElement(set2, B_nums);

	cout << GetAnswer(set1, set2);
	return 0;
}