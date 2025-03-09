#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void DFS(const vector<int>& students, vector<bool>& visited, vector<bool>& done, int& teamMembers, int node)
{
    visited[node] = true;
    int nextStudent = students[node];

    if (!visited[nextStudent]) DFS(students, visited, done, teamMembers, nextStudent);
    else if (!done[nextStudent])
    {
        for (int i = nextStudent; i != node; i = students[i]) teamMembers++;
        teamMembers++;
    }

    done[node] = true;
}


int main()
{
    FAST_IO
    int T, N;
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> students(N + 1);
        vector<bool> visited(N + 1, false);
        vector<bool> done(N + 1, false);

        for (int i = 1; i <= N; i++) cin >> students[i];

        int teamMembers = 0;
        for (int i = 1; i <= N; i++)
            if (!visited[i])
                DFS(students, visited, done, teamMembers, i);
        
        cout << N - teamMembers << "\n";
    }

    return 0;
}