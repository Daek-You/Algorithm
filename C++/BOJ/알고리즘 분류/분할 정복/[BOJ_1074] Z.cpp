#include <iostream>
#include <cmath>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N, r, c;

void Traversal(int sideLength, int row, int col, int& order) {
    if (sideLength < 2)
        return;
    
    int halfLength = sideLength / 2;

    for (int ri = row; ri < row + sideLength; ri += halfLength) {
        for (int ci = col; ci < col + sideLength; ci += halfLength) {
            bool isExistInCurrentSquareWidth = (ci <= c and c < ci + halfLength);
            bool isExistInCurrentSquareHeight = (ri <= r and r < ri + halfLength);

            if (isExistInCurrentSquareWidth and isExistInCurrentSquareHeight) {
                Traversal(halfLength, ri, ci, order);
                return;
            }
            
            order += halfLength * halfLength;
        }
    }
}


int main() {
    FAST_IO
    cin >> N >> r >> c;

    N = static_cast<int>(pow(2, N));
    int order = 0;

    Traversal(N, 0, 0, order);
    cout << order;

    return 0;
}