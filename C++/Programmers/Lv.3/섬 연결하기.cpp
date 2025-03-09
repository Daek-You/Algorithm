#include <vector>
#include <algorithm>
using namespace std;

/* references : https://m.blog.naver.com/fbfbf1/222278788809 */
class DisjointSet
{
public:
    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = Find(parent[node]);
    }

    void Merge(int node1, int node2)
    {
        node1 = Find(node1), node2 = Find(node2);
        if (node1 == node2)
            return;

        if (rank[node1] > rank[node2])
            swap(node1, node2);

        parent[node1] = node2;

        if (rank[node1] == rank[node2])
            rank[node2]++;
    }

    bool IsInSameSet(int node1, int node2)
    {
        node1 = Find(node1), node2 = Find(node2);
        return node1 == node2;
    }
private:
    vector<int> parent;
    vector<int> rank;
};


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    DisjointSet ds(n);
    
    sort(costs.begin(), costs.end(), [](const vector<int>& c1, const vector<int>& c2) { return c1[2] < c2[2]; });
    for (const auto& cost : costs)
    {
        int node1 = cost[0], node2 = cost[1];
        if (ds.IsInSameSet(node1, node2))
            continue;

        ds.Merge(node1, node2);
        answer += cost[2];
    }

    return answer;
}