#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

class DisjointSet
{
public:
    DisjointSet(int N) : parent(N + 1), rank(N + 1)
    {
        for (int i = 1; i <= N; i++)
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

    DisjointSet set(N);
    bool isConnected;
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            cin >> isConnected;
            if (isConnected)
                set.Union(row, col);
        }
    }

    int cityA, cityB;
    cin >> cityA;

    for (int i = 1; i < M; i++)
    {
        cin >> cityB;

        if (!set.IsSame(cityA, cityB))
        {
            cout << "NO";
            return 0;
        }

        cityA = cityB;
    }

    cout << "YES";

    return 0;
}