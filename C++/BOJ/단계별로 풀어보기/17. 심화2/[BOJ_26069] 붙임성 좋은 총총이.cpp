#include <iostream>
#include <set>
using std::cout;
using std::cin;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	std::set<std::string> dancingPeople;
	
	for (int i = 0; i < N; i++)
	{
		std::string human1, human2;
		cin >> human1 >> human2;

		if (human1 == "ChongChong" or human2 == "ChongChong")
		{
			std::string nextDancer = (human1 == "ChongChong") ? human2 : human1;
			dancingPeople.insert(nextDancer);
			continue;
		}

		auto human1It = dancingPeople.find(human1);
		auto human2It = dancingPeople.find(human2);

		// 서로 만난 사람이 둘 다 춤추는 사람이거나, 둘 다 춤추지 않는 사람일 경우
		if ((human1It == dancingPeople.end() and human2It == dancingPeople.end()) or (human1It != dancingPeople.end() and human2It != dancingPeople.end()))
			continue;

		std::string nextDancer = (human1It != dancingPeople.end()) ? human2 : human1;
		dancingPeople.insert(nextDancer);
	}

	cout << dancingPeople.size() + 1;
	return 0;
}