#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

class ReportInfo {
public:
	ReportInfo(const string& name, int index) : _myName(name), _index(index) { }

	void Reported(const ReportInfo& reporter) {
		auto iter = _reporters.find(reporter._myName);
		if (iter != _reporters.end())
			return;

		_reporters.insert(make_pair(reporter._myName, reporter._index));
	}

	bool IsSuspended(int k) { return _reporters.size() >= k; }

public:
	string _myName;
	int _index;
	map<string, int> _reporters;
};


map<string, ReportInfo> CreateUserInfo(const vector<string>& id_list) {
	map<string, ReportInfo> result;

	for (int i = 0; i < id_list.size(); i++)
		result.insert(make_pair(id_list[i], ReportInfo(id_list[i], i)));
	return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size(), 0);
	map<string, ReportInfo> people = CreateUserInfo(id_list);


	for (const auto info : report) {
		istringstream tokenizer(info);
		string reporter, user;

		tokenizer >> reporter >> user;
		auto reporterIt = people.find(reporter);
		auto userIt = people.find(user);

		userIt->second.Reported(reporterIt->second);
	}

	for (const auto person : people) {
		ReportInfo info = person.second;

		if (info.IsSuspended(k)) {
			for (const auto reporter : info._reporters) {
				int reporterIndex = reporter.second;
				answer[reporterIndex]++;
			}
		}
	}

	return answer;
}