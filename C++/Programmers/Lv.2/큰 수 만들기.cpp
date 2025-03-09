#include <string>
#include <deque>
using namespace std;

string solution(string number, int k) {
    deque<char> selectedNums;
    int removeCount = k;

    for (const auto& num : number)
    {
        if (selectedNums.empty() or num <= selectedNums.back()) {
            selectedNums.emplace_back(num);
            continue;
        }

        while (!selectedNums.empty() and (selectedNums.back() < num) and (removeCount > 0)) {
            removeCount--;
            selectedNums.pop_back();
        }

        selectedNums.emplace_back(num);
    }

    /*
        - 내림차순으로 정렬된 number의 경우, removeCount를 다 소모하기 전에 for문이 끝남
        - 따라서, 해당 removeCount만큼 뒷 숫자를 제거
    */
    for (int i = 0; i < removeCount; i++)
        selectedNums.pop_back();
    return string(selectedNums.begin(), selectedNums.end());
}