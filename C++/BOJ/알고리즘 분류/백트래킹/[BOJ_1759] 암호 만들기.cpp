#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Decoder
{
public:
	Decoder(int L, int C);
	void FindPasswords();
	void ShowPasswords();

private:
	void FindCombination(string password, int vowelIdx, int consonantIdx, int vowelCount, int consonantCount);

private:
	const set<char> VOWEL{ 'a', 'e', 'i', 'o', 'u' };
	string _vowels;
	string _consonants;
	set<string> _answers;

	int _L;
};

Decoder::Decoder(int L, int C)
{
	_L = L;

	for (int i = 0; i < C; i++)
	{
		char alphabet;
		cin >> alphabet;

		auto FindIter = VOWEL.find(alphabet);
		FindIter == VOWEL.end() ? _consonants.push_back(alphabet) : _vowels.push_back(alphabet);
	}
}

void Decoder::ShowPasswords()
{
	for (const auto& answer : _answers)
		cout << answer << "\n";
}

void Decoder::FindCombination(string password, int vowelIdx, int consonantIdx, int vowelCount, int consonantCount)
{
	if (password.length() == _L)
	{
		sort(password.begin(), password.end());
		_answers.emplace(password);
		return;
	}

	// 모음은 최소 1개부터 최대 L-2개까지 가질 수 있음
	for (int vi = vowelIdx; vi < _vowels.size() and vowelCount < _L - 2; vi++)
	{
		password.push_back(_vowels[vi]);
		FindCombination(password, vi + 1, consonantIdx, vowelCount + 1, consonantCount);
		password.pop_back();
	}

	// 자음은 최소 2개부터 최대 L-1개까지 가질 수 있음
	for (int ci = consonantIdx; ci < _consonants.size() and consonantCount < _L - 1; ci++)
	{
		password.push_back(_consonants[ci]);
		FindCombination(password, vowelIdx, ci + 1, vowelCount, consonantCount + 1);
		password.pop_back();
	}
}

void Decoder::FindPasswords()
{
	string password = "";
	FindCombination(password, 0, 0, 0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int L, C;
	cin >> L >> C;

	Decoder decoder(L, C);
	decoder.FindPasswords();
	decoder.ShowPasswords();
	return 0;
}