#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int GetFinalNumOfBottles(int N)
{
    int bottles = 0;

    while (N != 0)
    {
        if (N % 2 == 1) bottles++;
        N /= 2;
    }

    return bottles;
}

int GetAnswer(int N, const int K)
{
    if (N <= K)
        return 0;
    
    int newNumOfBottles = 0;

    while (true)
    {
        int bottles = GetFinalNumOfBottles(N);
        if (bottles <= K) break;

        newNumOfBottles++, N++;        
    }

    return newNumOfBottles;
}


int main()
{
    FAST_IO
    int N, K;
    cin >> N >> K;

    cout << GetAnswer(N, K);
    return 0;
}
