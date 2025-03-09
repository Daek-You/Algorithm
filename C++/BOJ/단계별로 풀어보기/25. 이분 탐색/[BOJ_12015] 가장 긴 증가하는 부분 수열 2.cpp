#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

int GetPositionWithBinarySearch(const vector<int>& arr, int data)
{
	if (arr.empty())
		return 0;
	return lower_bound(arr.begin(), arr.end(), data) - arr.begin();
}

int main()
{
	FAST_IO;

	int N;
	cin >> N;

	vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		cin >> sequence[i];


	vector<int> answer;
	for (const auto& element : sequence)
	{
		int index = GetPositionWithBinarySearch(answer, element);
		
		if (index < answer.size())
			answer[index] = element;
		else
			answer.emplace_back(element);
	}

	cout << answer.size();
	return 0;
}