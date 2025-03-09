#include <iostream>
#include <vector>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N;
vector<int> InOrder, IndexesOfInOrder, PostOrder;

void DivideAndConquer(int inOrderStart, int inOrderLast, int postOrderStart, int postOrderLast) {
    if (inOrderLast < inOrderStart or postOrderLast < postOrderStart)
        return;
    
    int rootIndex = IndexesOfInOrder[PostOrder[postOrderLast]];
    int root = InOrder[rootIndex];
    int leftSize = rootIndex - inOrderStart;

    cout << root << " ";

    DivideAndConquer(inOrderStart, rootIndex - 1, postOrderStart, postOrderStart + leftSize - 1);
    DivideAndConquer(rootIndex + 1, inOrderLast, postOrderStart + leftSize, postOrderLast - 1);
}

int main() {
    FAST_IO
    cin >> N;

    InOrder.resize(N + 1);
    IndexesOfInOrder.resize(N + 1);
    PostOrder.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> InOrder[i];
        IndexesOfInOrder[InOrder[i]] = i;
    }

    for (int i = 1; i <= N; i++)
        cin >> PostOrder[i];

    DivideAndConquer(1, N, 1, N);
    return 0;
}