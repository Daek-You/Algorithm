#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void Register(set<string>& _set, int n)
{
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		_set.insert(name);
	}
}


int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int noHearPeopleNums, noSeePeopleNums;
	cin >> noHearPeopleNums >> noSeePeopleNums;

	set<string> noHearPeople;
	set<string> noSeePeople;
	Register(noHearPeople, noHearPeopleNums);
	Register(noSeePeople, noSeePeopleNums);

	vector<string> answers(noHearPeopleNums + noSeePeopleNums);
	auto lastInsertIter = set_intersection(noHearPeople.begin(), noHearPeople.end(), noSeePeople.begin(), noSeePeople.end(), answers.begin());
	answers.erase(lastInsertIter, answers.end());

	cout << answers.size() << '\n';
	for (const auto answer : answers)
		cout << answer << '\n';
	return 0;
}
