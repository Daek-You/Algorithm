#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string Calculate(int N, int B, map<int, char>& decimalOverSystemAlphabets)
{
	int powValue = 0;
	string answer;
	bool isLastStep = false;

	while (true)
	{
		if (isLastStep && N % B == 0)
			break;

		auto findIt = decimalOverSystemAlphabets.find(N % B);
		char data = (findIt != decimalOverSystemAlphabets.end()) ? findIt->second : N % B + '0';
		answer.push_back(data);
		N /= B;

		if (N / B == 0)
			isLastStep = true;
	}

	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, B;
	cin >> N >> B;

	map<int, char> decimalOverSystemAlphabets;
	const int upperA_ASCII_CODE = 65;

	for (int i = 0; i < 26; i++)
	{
		decimalOverSystemAlphabets.insert(make_pair(10 + i, static_cast<char>(upperA_ASCII_CODE + i)));
	}

	string answer = Calculate(N, B, decimalOverSystemAlphabets);
	cout << answer;
	return 0;
}