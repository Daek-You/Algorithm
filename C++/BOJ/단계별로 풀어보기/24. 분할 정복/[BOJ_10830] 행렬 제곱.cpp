#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<long long>>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MOD 1000

int N;
long long B;

Matrix operator*(const Matrix& A, const Matrix& B) {
    Matrix result(N, vector<long long>(N));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            for (int i = 0; i < N; i++)
                result[row][col] += (A[row][i] * B[i][col]) % MOD;
            result[row][col] %= MOD;
        }
    }

    return result;
}

void Print(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row)
            cout << element << " ";
        cout << "\n";
    }
}

int main() {
    FAST_IO
    cin >> N >> B;

    Matrix matrix(N, vector<long long>(N));
    Matrix answer(N, vector<long long>(N));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cin >> matrix[row][col];
        answer[row][row] = 1;               // 첫 계산을 위해, 항등 행렬 생성
    }

    while (B > 0) {
        if (B % 2 != 0)
            answer = answer * matrix;
        matrix = matrix * matrix;
        B /= 2;
    }

    Print(answer);
    return 0;
}
