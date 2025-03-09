#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	cin.ignore();

	set<string> peopleInCompany;
	for (int i = 0; i < N; i++)
	{
		string log;
		getline(cin, log);

		stringstream forSplitingString(log);
		string name, breakdown;
		forSplitingString >> name >> breakdown;

		auto findIt = peopleInCompany.find(name);
		if (findIt != peopleInCompany.end() && breakdown == "leave")
			peopleInCompany.erase(findIt);
		else if (findIt == peopleInCompany.end() && breakdown == "enter")
			peopleInCompany.insert(name);
	}

	for (auto it = peopleInCompany.rbegin(); it != peopleInCompany.rend(); ++it)
		cout << *it << '\n';
	return 0;
}
