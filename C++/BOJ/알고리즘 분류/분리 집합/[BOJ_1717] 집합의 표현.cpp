#include <iostream>
#include <vector>
#include <string>

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
    string IsSame(int x, int y) { return Find(x) == Find(y) ? "YES" : "NO"; }
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
    int n, m;
    cin >> n >> m;

    DisjointSet set(n);
    for (int i = 0; i < m; i++)
    {
        int instruction, setA, setB;
        cin >> instruction >> setA >> setB;

        switch(instruction)
        {
            case 0:
                set.Union(setA, setB);
                break;
            case 1:
                cout << set.IsSame(setA, setB) << "\n";
                break;
        }
    }

    return 0;
}