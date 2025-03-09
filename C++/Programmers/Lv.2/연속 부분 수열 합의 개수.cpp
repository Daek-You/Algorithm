#include <set>
#include <deque>
#include <vector>
using namespace std;


int Sum(const deque<int>& myDeque, int selection) {
    int sum = 0;
 
    for (int i = 0; i < selection; i++)
        sum += myDeque[i];
    return sum;
}

deque<int> MigrationToDeque(const vector<int>& elements) {
    deque<int> result(elements.size());

    for (int i = 0; i < result.size(); i++)
        result[i] = elements[i];
    return result;
}

int solution(vector<int> elements) {
    deque<int> myDeque = MigrationToDeque(elements);
    set<int> answers;

    for (int selection = 1; selection < myDeque.size(); selection++) {
        for (int start = 0; start < myDeque.size(); start++) {
            int sum = Sum(myDeque, selection);
            answers.insert(sum);
            
            int front = myDeque.front();
            myDeque.push_back(front);
            myDeque.pop_front();
        }
    }

    int sum = Sum(myDeque, myDeque.size());      // 전부 선택하는 것은 바꿔가며 해도 값이 똑같으므로 한 번만 수행
    answers.insert(sum);
    return answers.size();
}