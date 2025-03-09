#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void PostOrderTraversal(const vector<int>& inorders, int start, int end)
{
    if (start >= end) return;
    if (start == end - 1)
    {
        cout << inorders[start] << "\n";
        return;
    }

    int leftNode = start + 1, rightNode = start + 1;
    while (rightNode < end and inorders[rightNode] <= inorders[start]) rightNode++;

    PostOrderTraversal(inorders, leftNode, rightNode);
    PostOrderTraversal(inorders, rightNode, end);
    cout << inorders[start] << "\n";
}

int main()
{
    FAST_IO
    int element;
    vector<int> inorders;
    while (cin >> element) inorders.push_back(element);
    
    PostOrderTraversal(inorders, 0, inorders.size());
    return 0;
}