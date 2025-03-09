#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    Node(int id, int x, int y) : id(id), x(x), y(y) { }

    int id, x, y;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};

void MakeBinaryTree(Node* root, Node* child)
{
    bool isLeftChild = child->x < root->x;
    bool isRightChild = root->x < child->x;

    if (isLeftChild)
    {
        if (root->leftChild == nullptr)
        {
            root->leftChild = child;
            return;
        }

        MakeBinaryTree(root->leftChild, child);
    }

    else if (isRightChild)
    {
        if (root->rightChild == nullptr)
        {
            root->rightChild = child;
            return;
        }

        MakeBinaryTree(root->rightChild, child);
    }
}

void PreOrder(Node* node, vector<int>& preOrder)
{
    if (node == nullptr)
        return;

    preOrder.push_back(node->id);
    PreOrder(node->leftChild, preOrder);
    PreOrder(node->rightChild, preOrder);
}

void PostOrder(Node* node, vector<int>& postOrder)
{
    if (node == nullptr)
        return;

    PostOrder(node->leftChild, postOrder);
    PostOrder(node->rightChild, postOrder);
    postOrder.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    // 1. 노드에 필요한 값들을 세팅하여 새로운 배열에 저장
    vector<Node> binaryTree;
    for (int i = 0; i < nodeinfo.size(); i++)
        binaryTree.emplace_back(Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));

    // 2. 루트 노드부터 트리를 만들 수 있도록 정렬    
    sort(binaryTree.begin(), binaryTree.end(),
    [](const Node& node1, const Node& node2)
    {
        if (node1.y == node2.y)
            return node1.x < node2.x;
        return node1.y > node2.y;
    });

    // 3. 루트 노드부터 시작하여 이진트리 구축
    Node* rootNode = &binaryTree[0];
    for (int i = 1; i < binaryTree.size(); i++)
        MakeBinaryTree(rootNode, &binaryTree[i]);

    // 4. 전위순회, 후위순회 결괏값 반환
    vector<int> preOrderResult, postOrderResult;
    PreOrder(rootNode, preOrderResult);
    PostOrder(rootNode, postOrderResult);

    vector<vector<int>> answer {preOrderResult, postOrderResult};

    return answer; 
}