#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
using uint64 = unsigned long long;

uint64 Pow(uint64 A, int B, const int C)
{
    if (B <= 1)
        return A % C;

    int numCount = B / 2;
    int mod = B % 2;

    uint64 square = (A * A) % C;
    uint64 modNum = (mod == 0) ? 1 : A;
    
    return (modNum * Pow(square, numCount, C)) % C;
}

/*
            1679616
       1296        1296      36
     36    36    36    36    36   6
    6  6  6  6  6  6  6  6  6  6  6

*/

int main()
{
    FAST_IO
    int A, B, C;
    cin >> A >> B >> C;

    uint64 answer = Pow(A, B, C);
    cout << answer;
    return 0;
}
