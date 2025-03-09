#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

template<typename T>
class DisjointSet {
public:
    DisjointSet(int size) : parent(size), rank(size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

public:
    T Find(const T& element) {
        if (element == parent[element])
            return element;
        
        T root = Find(parent[element]);
        parent[element] = root;
        return root;
    }

    void Union(const T& x, const T& y) {
        T xRoot = Find(x);
        T yRoot = Find(y);

        if (xRoot == yRoot)
            return;

        // 두 집합의 높이가 같은 경우에는 y를 x의 자식으로 넣는 걸로 정하였음
        // 이럴 경우, 전체 트리의 높이는 "x의 높이 + 1"이 됨
        if (rank[xRoot] == rank[yRoot]) {
            parent[yRoot] = xRoot;
            rank[xRoot] += 1;
        }

        else if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else
            parent[yRoot] = xRoot;
    }

    inline bool IsSame(const T& x, const T& y) { return Find(x) == Find(y); }

private:
    vector<T> parent;
    vector<T> rank;
};

struct Edge {
    Edge() { }
    Edge(int n1, int n2, int cost) : node1(n1), node2(n2), cost(cost) { }
    bool operator<(const Edge& other) const { return cost > other.cost; }
    int node1, node2, cost;
};

int main() {
    FAST_IO
    int N, M;
    cin >> N >> M;

    DisjointSet<int> unionFind(N + 1);
    priority_queue<Edge> edges;
    int node1, node2, cost;

    for (int i = 0; i < M; i++) {
        cin >> node1 >> node2 >> cost;
        edges.emplace(node1, node2, cost);
    }

    vector<int> answers;
    while (!edges.empty()) {
        Edge current = edges.top();
        edges.pop();

        int node1 = current.node1;
        int node2 = current.node2;
        int cost = current.cost;

        if (unionFind.IsSame(node1, node2))
            continue;

        unionFind.Union(node1, node2);
        answers.emplace_back(cost);
    }

    int answer = 0;
    for (int i = 0; i < answers.size() - 1; i++)
        answer += answers[i];
    cout << answer;
    return 0;
}
