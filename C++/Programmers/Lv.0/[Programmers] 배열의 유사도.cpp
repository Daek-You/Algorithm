#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for(const auto elementS1 : s1)
    {
        for(const auto elementS2 : s2)
        {
            if(elementS1 == elementS2)
                answer++;
        }
    }
    
    return answer;
}