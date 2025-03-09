#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int ALPHABET_COUNT = 26;
const int LOWER_A_ASCII = 97;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int quesitionCount;
	string sequence;
	cin >> sequence >> quesitionCount;

	// 1. 각 알파벳마다, 나오는 위치들을 저장
	vector<vector<int>> alphabetPositions(ALPHABET_COUNT);
	for (int i = 0; i < sequence.length(); i++)
	{
		int index = sequence[i] - LOWER_A_ASCII;
		alphabetPositions[index].emplace_back(i);
	}

	// 2. 이진 탐색을 이용하여, 인덱스 차이를 계산 후 출력
	for (int i = 0; i < quesitionCount; i++)
	{
		char find;
		int l, r;
		cin >> find >> l >> r;

		int index = find - LOWER_A_ASCII;
		int start = lower_bound(alphabetPositions[index].begin(), alphabetPositions[index].end(), l) - alphabetPositions[index].begin();
		int last = upper_bound(alphabetPositions[index].begin(), alphabetPositions[index].end(), r) - alphabetPositions[index].begin();

		cout << last - start << "\n";
	}

	return 0;
}