#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isFindAnswer = false;

void DFS(string currentStation, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answers, int ticketCount)
{
    answers.push_back(currentStation);

    if (ticketCount == tickets.size())
    {
        isFindAnswer = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i] or tickets[i][0] != currentStation)
            continue;

        visited[i] = true;
        DFS(tickets[i][1], tickets, visited, answers, ticketCount + 1);

        if (isFindAnswer)
            return;
        answers.pop_back();
        visited[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answers;
    int ticketCount = tickets.size();
    vector<bool> visited(ticketCount, false);

    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, visited, answers, 0);
    return answers;
}