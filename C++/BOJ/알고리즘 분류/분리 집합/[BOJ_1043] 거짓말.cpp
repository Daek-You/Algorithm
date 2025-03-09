#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

class DisjointSet
{
public:
    DisjointSet(int N) : parent(N + 1), rank(N + 1)
    {
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    void Union(int x, int y);
    bool IsSame(int x, int y) { return Find(x) == Find(y); }
private:
    int Find(int x);

private:
    vector<int> parent;
    vector<int> rank;
};

int DisjointSet::Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void DisjointSet::Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX == rootY)
        return;

    if (rank[rootX] == rank[rootY])
    {
        parent[rootY] = rootX;
        rank[rootX] += 1;
    }
    else if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else
        parent[rootY] = rootX;
}

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    DisjointSet truthSet(N);
    int personCount;
    cin >> personCount;

    vector<int> truthMans(personCount);
    for (int i = 0; i < personCount; i++)
        cin >> truthMans[i];

    int answer = M;
    vector<vector<int>> parties(M);

    for (int i = 0; i < M; i++)
    {
        cin >> personCount;
        vector<int> party(personCount);
        cin >> party[0];

        for (int j = 1; j < personCount; j++)
        {
            cin >> party[j];
            truthSet.Union(party[j - 1], party[j]);
        }

        parties[i] = party;
    }

    for (int i = 0; i < M; i++)
    {
        bool lie = true;

        for (const auto partyMan : parties[i])
        {
            if (!lie) break;

            for (const auto truthMan : truthMans)
            {
                if (truthSet.IsSame(partyMan, truthMan))
                {
                    lie = false;
                    break;
                }
            }
        }

        if (!lie)
            answer--;
    }

    cout << answer;
    return 0;
}