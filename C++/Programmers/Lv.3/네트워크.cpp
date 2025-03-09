#include <vector>
using namespace std;

vector<vector<int>>* GetLinkState(int n, const vector<vector<int>>& computers)
{
    vector<vector<int>>* result = new vector<vector<int>>();
    for (int row = 0; row < n; row++)
    {
        vector<int> link;
        for (int col = 0; col < n; col++)
        {
            if (row == col)
                continue;

            if (computers[row][col])
                link.push_back(col);
        }

        result->push_back(link);
    }

    return result;
}

void DFS(const vector<vector<int>>& links, vector<bool>& visited, int current)
{
    visited[current] = true;
    for (const auto& link : links[current])
    {
        if (visited[link])
            continue;
        DFS(links, visited, link);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    auto linkState = GetLinkState(n, computers);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        DFS(*linkState, visited, i);
        answer++;
    }

    delete linkState;
    return answer;
}