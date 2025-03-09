#include <vector>
using namespace std;
const int DIVISION = 1234567;

int solution(int n) {
    vector<int> F(n + 1);
    F[0] = 0;
    F[1] = 1;
    
    for (int i = 2; i <= n ; i++)
        F[i] = (F[i-1] + F[i-2]) % DIVISION;
    return F[n];
}