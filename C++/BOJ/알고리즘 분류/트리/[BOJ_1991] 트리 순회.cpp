#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Node = pair<char, char>;  // <왼쪽 자식, 오른쪽 자식>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define A_NODE 'A'
#define LEAF_NODE '.'

auto ConvertAlphabetToIntIndex = [](char alphabet) -> int  { return alphabet - A_NODE; };

void PreOrder(const vector<Node>& binaryTree, int N, vector<bool>& visited, char node)
{
    int index = ConvertAlphabetToIntIndex(node);

    if (index < 0 or N <= index or visited[index])
        return;
    
    visited[index] = true;
    cout << node;
    PreOrder(binaryTree, N, visited, binaryTree[index].first);
    PreOrder(binaryTree, N, visited, binaryTree[index].second);
}

void InOrder(const vector<Node>& binaryTree, int N, vector<bool>& visited, char node)
{
    int index = ConvertAlphabetToIntIndex(node);

    if (index < 0 or N <= index or visited[index])
        return;
    
    visited[index] = true;
    InOrder(binaryTree, N, visited, binaryTree[index].first);
    cout << node;
    InOrder(binaryTree, N, visited, binaryTree[index].second);
}

void PostOrder(const vector<Node>& binaryTree, int N, vector<bool>& visited, char node)
{
    int index = ConvertAlphabetToIntIndex(node);

    if (index < 0 or N <= index or visited[index])
        return;
    
    visited[index] = true;
    PostOrder(binaryTree, N, visited, binaryTree[index].first);
    PostOrder(binaryTree, N, visited, binaryTree[index].second);
    cout << node;
}

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<Node> binaryTree(N);
    for (int i = 0; i < N; i++)
    {
        char currentNode, leftChildNode, rightChildNode;
        cin >> currentNode >> leftChildNode >> rightChildNode;
        
        int currentNodeIndex = ConvertAlphabetToIntIndex(currentNode);

        binaryTree[currentNodeIndex].first = leftChildNode;
        binaryTree[currentNodeIndex].second = rightChildNode;
    }

    vector<bool> visited(N, false);
    PreOrder(binaryTree, N, visited, A_NODE);
    cout << "\n";

    std::fill(visited.begin(), visited.end(), false);
    InOrder(binaryTree, N, visited, A_NODE);
    cout << "\n";

    std::fill(visited.begin(), visited.end(), false);
    PostOrder(binaryTree, N, visited, A_NODE);
    return 0;
}