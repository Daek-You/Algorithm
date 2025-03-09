#include <iostream>
#include <queue>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    int N, data;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> huffmanTree;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        huffmanTree.push(data);
    }

    int answer = 0;
    while (huffmanTree.size() > 1)
    {
        int cardPackage1 = huffmanTree.top();
        huffmanTree.pop();

        int cardPackage2 = huffmanTree.top();
        huffmanTree.pop();

        int compareCount = cardPackage1 + cardPackage2;
        answer += compareCount; 
        huffmanTree.push(compareCount);
    }

    cout << answer;
    return 0;
}