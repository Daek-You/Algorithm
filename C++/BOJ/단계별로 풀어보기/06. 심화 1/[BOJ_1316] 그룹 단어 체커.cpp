#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int wordNums;
	cin >> wordNums;

	int answer = 0;
	const int lower_A_ASCII = 97;

	for (int i = 0; i < wordNums; i++)
	{
		int alphabets[26] = { 0 };
		string word;
		cin >> word;

		int preIndex = -1;
		bool isGroupWord = true;

		for (auto alphabet : word)
		{
			int index = alphabet - lower_A_ASCII;  // a ~ z까지 차례대로 인덱스 0 ~ 25번을 가짐

			/*
				이전 알파벳과 현재 알파벳이 다르다고, 현재 알파벳이 나왔던 횟수가 0이 아니라면
				이전에 이미 나왔었던 알파벳이므로 그룹단어 X
			*/
			if (preIndex != index && alphabets[index] != 0)
			{
				isGroupWord = false;
				break;
			}

			alphabets[index]++;
			preIndex = index;
		}

		if (isGroupWord)
			answer++;
	}

	cout << answer;
	return 0;
}