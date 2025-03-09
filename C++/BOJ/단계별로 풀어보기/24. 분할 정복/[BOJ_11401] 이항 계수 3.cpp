#include <iostream>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
const int MOD =  1000000007;

long long Pow(int n, int k) {
    if (k == 1)
        return n % MOD;
    
    long long temp = Pow(n, k / 2);
    temp = temp * temp % MOD;
    return k % 2 == 0 ? temp % MOD : n * temp % MOD;
}

int main() {
    FAST_IO
    int N, K;
    cin >> N >> K;
    
    // nCk = n! * (k!(n - k)!)^-1
    //     = (n * n -1 * ... * n - k + 1) * k!^{-1}
    
    // -> k!^{10^9 + 7 - 2} = k!^{-1} mod (10^9 + 7)  -> 페르마의 소정리
    // 따라서, nCk = (n * n -1 * ... * n - k + 1) * k!^{10^9 + 7 - 2}
    //        -> C = A * B 라고 치환하여 계산

    long long A = 1;
    for (int i = N; i >= N - K + 1; i--)
        A = (A * i) % MOD;

    long long base = 1;
    for (int i = 1; i <= K; i++)
        base = (base * i) % MOD;

    long long B = Pow(base, MOD - 2);
    cout << (A * B) % MOD;
    return 0;
}
