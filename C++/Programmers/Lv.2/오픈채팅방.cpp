#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
const int INSTRUCTION = 0;
const int ID = 1;
const int NICKNAME = 2;

unordered_map<string, string> ChatMessages { {"Enter", "님이 들어왔습니다."}, { "Leave", "님이 나갔습니다." } };

class User {
public:
    User() { }
    User(string id, string nickName) : _id(id), _nickName(nickName) { }
    string GetMessage(const string& instruction) { return _nickName + ChatMessages[instruction]; }
    void ChangeNickName(const string& newNickName) { _nickName = newNickName; }
    string GetId() { return _id; }
    string GetNickName() { return _nickName; }

private:
    string _id;
    string _nickName;
};


vector<string> Split(const string& log) {
    vector<string> result;
    stringstream tokenizer(log);
    string buffer;

    while (getline(tokenizer, buffer, ' '))
        result.push_back(buffer);
    return result;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, User> users;

    // 유저 등록 및 닉네임 변경 작업
    for (const auto log : record) {
        vector<string> contents = Split(log);
        auto it = users.find(contents[ID]);

        if (contents[INSTRUCTION] == "Leave")
            continue;

        // 첫 접속
        if (it == users.end()) {
            users.emplace(contents[ID], User(contents[ID], contents[NICKNAME]));
            continue;
        }

        // 나갔다 들어왔거나, 닉네임을 변경하는 경우
        if (contents[INSTRUCTION] == "Enter" or contents[INSTRUCTION] == "Change")
            users[contents[ID]].ChangeNickName(contents[NICKNAME]);
    }

    // 출력 결과물 담기
    for (const auto log : record) {
        vector<string> informations = Split(log);
        if (informations[INSTRUCTION] != "Change")
            answer.emplace_back(users[informations[ID]].GetMessage(informations[INSTRUCTION]));
    }

    return answer;
}