#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idxA = 0, idxB = 0;
    while(idxA < A.size() and idxB < B.size())
    {
        if (A[idxA] < B[idxB])
        {
            idxA++;
            idxB++;
            answer++;
            continue;
        }
        
        idxB++;
    }
    
    return answer;
}