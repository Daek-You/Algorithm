#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
bool answer = false;

void DFS(const vector<vector<int>>& friends, vector<bool>& visited, int node, int depth)
{
    if (depth == 4)
    {
        answer = true;
        return;
    }

    for (const int& otherFriend : friends[node])
    {
        if (visited[otherFriend])
            continue;
        visited[node] = true;
        DFS(friends, visited, otherFriend, depth + 1);
        visited[node] = false;
    }
}

int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<vector<int>> friends(N + 1, vector<int>());
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        vector<bool> visited(N + 1, false);
        visited[i] = true;
        DFS(friends, visited, i, 0);

        if (answer)
            break;
    }

    cout << answer;
    return 0;
}