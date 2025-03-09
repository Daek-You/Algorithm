#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int DFS(vector<vector<int>>& children, int node, int removeId)
{
    // 루트 노드를 제거하는 경우
    if (node == removeId)
        return 0;

    // 리프 노드인 경우
    if (children[node].empty())
        return 1;
    
    int leafNodeCount = 0;
    for (const int child : children[node])
    {
        if (child == removeId)
        {
            leafNodeCount += (children[node].size() == 1) ? 1 : 0;  // 부모 노드의 마지막 자식을 삭제하는 경우, 해당 부모 노드는 리프 노드가 됨
            continue;
        }

        leafNodeCount += DFS(children, child, removeId);
    }

    return leafNodeCount;
}

int main()
{
    FAST_IO
    int N, parentId, removeTargetId, root;
    cin >> N;

    vector<vector<int>> children(N, vector<int>());
    for (int childIndex = 0; childIndex < N; childIndex++)
    {
        cin >> parentId;

        if (parentId == -1)
            root = childIndex;
        else
            children[parentId].push_back(childIndex);
    }

    cin >> removeTargetId;
    int leafNodeCount = DFS(children, root, removeTargetId);
    cout << leafNodeCount;
    return 0;
}