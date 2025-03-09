#include <iostream>
#include <unordered_map>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

long long N, P, Q;
unordered_map<long long, long long> Sequences;  // <i, A_i>

long long DivideAndConquer(long long n)
{
    if (Sequences.find(n) != Sequences.end())
        return Sequences[n];
    return Sequences[n] = DivideAndConquer(n / P) + DivideAndConquer(n / Q);
}

int main()
{
    FAST_IO
    cin >> N >> P >> Q;
    Sequences.insert({0, 1});

    long long answer = DivideAndConquer(N);
    cout << answer;
    return 0;
}
