#include <string>
#include <vector>
#include <stack>
using namespace std;

bool IsCorrect(const string& parenthesises) {
	stack<char> pStack;

	for (const auto& p : parenthesises) {
		if (pStack.empty() and p == ')')
			return false;

		if (p == '(') {
			pStack.emplace(p);
			continue;
		}
		pStack.pop();
	}

	return pStack.empty();
}

string ConvertU(const string& u) {
	string result = "";

	for (int i = 1; i < u.length() - 1; i++) {
		if (u[i] == '(')
			result += ')';
		else
			result += '(';
	}

	return result;
}

pair<string, string> Split(const string& w) {
	int leftPCount = 0, rightPCount = 0, i = 0;
	string u, v;

	for (; i < w.length(); i++) {
		w[i] == '(' ? leftPCount++ : rightPCount++;

		if (leftPCount == rightPCount) {
			u = w.substr(0, i + 1);
			v = w.substr(i + 1);
			break;
		}
	}
	return make_pair(u, v);
}

string GetAnswer(string& w) {
	if (w.empty())
		return "";

	string answer = "";
	pair<string, string> uv = Split(w);

	if (IsCorrect(uv.first)) {
		answer = uv.first + GetAnswer(uv.second);
		return answer;
	}

	answer = "(";
	answer += GetAnswer(uv.second);
	answer += ')';
	answer += ConvertU(uv.first);
	return answer;
}

string solution(string p) {
	if (IsCorrect(p))
		return p;
	return GetAnswer(p);
}