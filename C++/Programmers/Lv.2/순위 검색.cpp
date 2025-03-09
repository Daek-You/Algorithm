#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
const int MAX_CATEGORIES = 4;

vector<string> Split(string str, const string delimiter) {
    int removeNums = delimiter.length();
    int startIdx = 0;
    vector<string> result;

    while (true) {
        int findIdx = str.find(delimiter, startIdx);

        if (findIdx == str.npos)
            break;

        string token = str.substr(startIdx, findIdx - startIdx);
        result.emplace_back(token);
        startIdx = findIdx + removeNums;
    }

    string remainedStr = str.substr(startIdx);
    istringstream tokenizer(remainedStr);
    string buffer;

    while (getline(tokenizer, buffer, ' ')) result.emplace_back(buffer);
    return result;
}

void RegistKey(map<string, vector<int>>& database, const vector<string>& tokens, string buffer, int idx) {
	if (idx == MAX_CATEGORIES) {
		database[buffer].emplace_back(stoi(tokens.back()));
		return;
	}

	RegistKey(database, tokens, buffer + tokens[idx], idx + 1);
	RegistKey(database, tokens, buffer + "-", idx + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    map<string, vector<int>> database;
    vector<int> answer;

    // 1. 16가지 경우의 모든 가능한 쿼리 데이터 저장하기
    for (const auto& data : info) {
        istringstream tokenizer(data);
        vector<string> tokens(MAX_CATEGORIES + 1);

        tokenizer >> tokens[0] >> tokens[1] >> tokens[2] >> tokens[3] >> tokens[4];
        RegistKey(database, tokens, "", 0);
    }

    // 2. 쿼리 내 데이터들 오름차순 정렬
    for (auto& info : database)
        sort(info.second.begin(), info.second.end());

    //// 3. 쿼리에 대한 답 추가하기
    for (const auto& request : query) {
        vector<string> splitStr = Split(request, " and ");
        int codingTestScore = stoi(splitStr.back());

        string key;
        for (int i = 0; i < splitStr.size() - 1; i++)
            key += splitStr[i];

        auto findIt = lower_bound(database[key].begin(), database[key].end(), codingTestScore);
        answer.emplace_back(database[key].size() - (findIt - database[key].begin()));
    }

    return answer;
}


/*      # 틀렸던 풀이
	정렬할 필요없이 바로바로 정렬되도록 처음에는 multiset을 사용했는데, 트리 구조를 변경하는 데에서 시간 소요가 많이 들었나 보다. 시간 초과가 떴다.

#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
using namespace std;
const int MAX_CATEGORIES = 4;

vector<string> Split(string str, const string delimiter) {
    int removeNums = delimiter.length();
    int startIdx = 0;
    vector<string> result;

    while (true) {
        int findIdx = str.find(delimiter, startIdx);

        if (findIdx == str.npos)
            break;

        string token = str.substr(startIdx, findIdx - startIdx);
        result.emplace_back(token);
        startIdx = findIdx + removeNums;
    }

    string remainedStr = str.substr(startIdx);
    istringstream tokenizer(remainedStr);
    string buffer;

    while (getline(tokenizer, buffer, ' ')) result.emplace_back(buffer);
    return result;
}

void RegistKey(map<string, multiset<int>>& database, const vector<string>& tokens, string buffer, int idx) {
	if (idx == MAX_CATEGORIES) {
		database[buffer].emplace(stoi(tokens.back()));
		return;
	}

	RegistKey(database, tokens, buffer + tokens[idx], idx + 1);
	RegistKey(database, tokens, buffer + "-", idx + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    map<string, multiset<int>> database;
    vector<int> answer;

    for (const auto& data : info) {
        istringstream tokenizer(data);
        vector<string> tokens(MAX_CATEGORIES + 1);

        tokenizer >> tokens[0] >> tokens[1] >> tokens[2] >> tokens[3] >> tokens[4];
        RegistKey(database, tokens, "", 0);
    }

    for (const auto& request : query) {
        vector<string> splitStr = Split(request, " and ");
        int codingTestScore = stoi(splitStr.back());

        string key;
        for (int i = 0; i < splitStr.size() - 1; i++)
            key += splitStr[i];

        auto it = database[key].lower_bound(codingTestScore);
        const auto offset = distance(database[key].begin(), it);
        answer.emplace_back(database[key].size() - offset);
    }

    return answer;
}
*/