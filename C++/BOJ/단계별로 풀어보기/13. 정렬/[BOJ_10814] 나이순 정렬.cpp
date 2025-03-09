#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Member
{
public:
	Member(int id, int age, string name) : _id(id), _age(age), _name(name) { }
	void Print() const { cout << _age << ' ' << _name << '\n'; }
	friend bool compare(const Member& m1, const Member& m2);
private:
	int _id;
	int _age;
	string _name;
};

bool compare(const Member& m1, const Member& m2)
{
	if (m1._age == m2._age)
		return m1._id < m2._id;
	return m1._age < m2._age;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Member> members;
	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		members.push_back(Member(i, age, name));
	}

	stable_sort(members.begin(), members.end(), compare);
	for (const auto member : members)
		member.Print();
	return 0;
}