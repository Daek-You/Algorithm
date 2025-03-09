#include <iostream>
#include <vector>
using namespace std;
int answer = 2147483647;

void CalculateSynergy(const vector<vector<int>>& ablilityMatrix, const vector<int>& people, vector<int>& result, int currentIdx, int& totalPoint)
{
    if (result.size() == 2)    // 두 명간의 시너지 효과 계산
    {
        int human1 = result[0];
        int human2 = result[1];

        totalPoint += (ablilityMatrix[human1][human2] + ablilityMatrix[human2][human1]);
        return;
    }

    for (int i = currentIdx; i < people.size(); i++)
    {
        result.push_back(people[i]);
        CalculateSynergy(ablilityMatrix, people, result, i + 1, totalPoint);
        result.pop_back();
    }
}

void FindOptimizedBalance(const vector<vector<int>>& abilityMatrix, const vector<int>& startTeam, const vector<int>& linkTeam)
{
    int startTeamPoint = 0;
    int linkTeamPoint = 0;
    vector<int> targetPeople;
    CalculateSynergy(abilityMatrix, startTeam, targetPeople, 0, startTeamPoint);
    CalculateSynergy(abilityMatrix, linkTeam, targetPeople, 0, linkTeamPoint);

    int difference = abs(startTeamPoint - linkTeamPoint);
    answer = answer > difference ? difference : answer;
}

void StartFindingOptimizedBalance(const vector<vector<int>>& abilityMatrix, const vector<bool>& teams)
{
    vector<int> startTeam, LinkTeam;
    for (int i = 0; i < teams.size(); i++)
    {
        if (!teams[i]) startTeam.push_back(i);
        else LinkTeam.push_back(i);
    }

    FindOptimizedBalance(abilityMatrix, startTeam, LinkTeam);
}

void DivideTwoTeams(const vector<vector<int>>& abilityMatrix, vector<bool>& teams, int totalPeopleNum, int currentIdx, int selectedPeopleNum)
{
    if (selectedPeopleNum == totalPeopleNum / 2)
    {
        StartFindingOptimizedBalance(abilityMatrix, teams);
        return;
    }

    for (int i = currentIdx; i < totalPeopleNum; i++)
    {
        if (!teams[i])
        {
            teams[i] = true;
            DivideTwoTeams(abilityMatrix, teams, totalPeopleNum, i + 1, selectedPeopleNum + 1);
            teams[i] = false;
        }
    }
}

void StartDividingTeams(const vector<vector<int>>& abilityMatrix, int N)
{
    vector<bool> teams(N, false);    // false : StartTeam, true : LinkTeam
    DivideTwoTeams(abilityMatrix, teams, N, 0, 0);
}

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> abilityMatrix(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        vector<int> abilityRow(N);
        for (int j = 0; j < N; j++)
        {
            int data;
            cin >> data;
            abilityRow[j] = data;
        }
        abilityMatrix[i] = abilityRow;
    }

    StartDividingTeams(abilityMatrix, N);
    cout << answer;
    return 0;
}