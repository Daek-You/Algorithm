#include <string>
using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = length - 1;

	for (int i = 0; i < length; i++) {
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int target = i + 1;
        while (target < length and name[target] == 'A') target++;

        /*
            - 첫 번째 위치를 기준으로 비교
            - 예를 들어, ABBAAAABA가 있고, i = 2, target = 7이라면,
                min(2*i + target, i + 2*target)을 선택    
        */
        move = min(move, i + (length - target) + min(i, length - target));
	}

    answer += move;
    return answer;
}