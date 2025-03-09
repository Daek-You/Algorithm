#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int Calculate(string N, int systemNumber, map<char, int>& decimalOverSystemAlphabets)
{
	int powValue = 0;
	int answer = 0;
	reverse(N.begin(), N.end());

	for (const char data : N)
	{
		// A ~ Z 이외에 입력은 안 들어올 것이므로
		int toIntData = (isdigit(data)) ? toIntData = data - '0' : decimalOverSystemAlphabets.find(data)->second;
		answer += toIntData * pow(systemNumber, powValue);
		powValue++;
	}

	return answer;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string N;
	int B;
	cin >> N >> B;

	map<char, int> decimalOverSystemAlphabets;
	const int upperA_ASCII_CODE = 65;

	for (int i = 0; i < 26; i++)
	{
		decimalOverSystemAlphabets.insert(make_pair(static_cast<char>(upperA_ASCII_CODE + i), 10 + i));
	}

	int answer = Calculate(N, B, decimalOverSystemAlphabets);
	cout << answer;
	return 0;
}