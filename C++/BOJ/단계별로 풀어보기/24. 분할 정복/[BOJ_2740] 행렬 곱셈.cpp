#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void Dot(Matrix& A, Matrix& B, int N, int M, int K) {
    for (int row = 0; row < N; row++) {
        int sum = 0;

        for (int col = 0; col < K; col++) {
            for (int i = 0; i < M; i++)
                sum += A[row][i] * B[i][col];
            cout << sum << " ";
            sum = 0;
        }
        cout << "\n";
    }
}

int main() {
    FAST_IO
    int N, M, K;
    cin >> N >> M;

    Matrix A(N, vector<int>(M));
    for (int row = 0; row < N; row++)
        for (int col = 0; col < M; col++)
            cin >> A[row][col];

    cin >> M >> K;
    Matrix B(M, vector<int>(K));
    for (int row = 0; row < M; row++)
        for (int col = 0; col < K; col++)
            cin >> B[row][col];
    
    Dot(A, B, N, M, K);
    return 0;
}
