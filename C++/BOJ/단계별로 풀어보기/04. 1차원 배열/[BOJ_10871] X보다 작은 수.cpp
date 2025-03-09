#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, X, temp;
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp < X)
            cout << temp << " ";
    }
    return 0;
}