#include <string>
#include <vector>
#include <set>
using namespace std;

bool IsAvailableCase(const string& userId, const string& bannedId)
{
    if (userId.length() != bannedId.length())
        return false;

    int N = userId.length();
    for (int i = 0; i < N; i++)
    {
        if (bannedId[i] == '*')
            continue;
        if (userId[i] != bannedId[i])
            return false;
    }

    return true;
}

void Combination(const vector<vector<string>>& blackLists, set<string>& answers, set<string>& current, int banIdx, int N)
{
    if (banIdx == N)
    {
        string temp;
        for (const string& str : current)
            temp += str;

        auto findIt = answers.find(temp);
        if (findIt == answers.end())
            answers.insert(temp);
        return;
    }

    for (int i = 0; i < blackLists[banIdx].size(); i++)
    {
        auto findIt = current.find(blackLists[banIdx][i]);
        if (findIt == current.end())
        {
            string str = blackLists[banIdx][i];
            current.insert(str);
            Combination(blackLists, answers, current, banIdx + 1, N);
            current.erase(str);
        }
    }
}

int GetCase(const vector<vector<string>>& blackLists, int N)
{
    set<string> answers;
    set<string> temp;

    Combination(blackLists, answers, temp, 0, N);
    return answers.size();
}


int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> blackLists(banned_id.size(), vector<string>());

    // 1. 주어진 banned_id 순서대로, 매칭이 되는 user_id를 추출
    for (int bi = 0; bi < banned_id.size(); bi++)
    {
        for (const string& uId : user_id)
        {
            if (IsAvailableCase(uId, banned_id[bi]))
                blackLists[bi].push_back(uId);
        }
    }

    // 2. 중복을 제외한 경우의 수 구하기
    int answer = GetCase(blackLists, banned_id.size());
    return answer;
}
