#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

unordered_map<string, double> RoyalScore;

string TopologicalSort(const unordered_map<string, vector<string>>& children, unordered_map<string, int>& inDegrees, const vector<string>& candidates, const string& kingName)
{
    queue<string> people;

    for (const auto& inDegree : inDegrees)
        if (inDegree.second == 0)
            people.push(inDegree.first);

    RoyalScore[kingName] = 1.0f;
    while (!people.empty())
    {
        string name = people.front();
        people.pop();

        auto royalPeopleIter = RoyalScore.find(name);
        double royalScore = (royalPeopleIter != RoyalScore.end()) ? royalPeopleIter->second : 0;

        auto childIterator = children.find(name);

        if (childIterator != children.end())
        {
            for (const string& child : childIterator->second)
            {
                RoyalScore[child] += (royalScore) / 2;

                if (--inDegrees[child] == 0)
                    people.emplace(child);
            }
        }
    }

    string answer = "";
    double score = -1;

    for (const string& candidate : candidates)
    {
        if (score < RoyalScore[candidate])
        {
            answer = candidate;
            score = RoyalScore[candidate];
        }
    }

    return answer;
}

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    unordered_map<string, vector<string>> children;
    unordered_map<string, int> inDegrees;

    // 1. 왕 이름과 왕족 점수 부여 
    string kingName;
    cin >> kingName;

    // 2. 부모와 자식 관계 및 점수 정리
    for (int i = 0; i < N; i++)
    {
        string child, father, mother;
        cin >> child >> father >> mother;

        children[father].emplace_back(child);
        children[mother].emplace_back(child);
        
        inDegrees[father];
        inDegrees[mother];
        inDegrees[child] += 2;
    }

    vector<string> candidates(M);
    for (int i = 0; i < M; i++)
        cin >> candidates[i];

    string answer = TopologicalSort(children, inDegrees, candidates, kingName);
    cout << answer;
    return 0;
}