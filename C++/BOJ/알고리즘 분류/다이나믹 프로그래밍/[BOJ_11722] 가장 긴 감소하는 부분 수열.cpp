#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int GetIndexWithBinarySearch(const vector<int> sequence, int data)
{
	if (sequence.empty())
		return 0;
	return lower_bound(sequence.begin(), sequence.end(), data) - sequence.begin();
}


int main()
{
	FAST_IO;

	int N;
	cin >> N;

	vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	
	reverse(sequence.begin(), sequence.end());
	vector<int> answer;
	for (int i = 0; i < N; i++)
	{
		int index = GetIndexWithBinarySearch(answer, sequence[i]);

		if (index < answer.size())
			answer[index] = sequence[i];
		else
			answer.emplace_back(sequence[i]);
	}

	cout << answer.size();
	return 0;
}