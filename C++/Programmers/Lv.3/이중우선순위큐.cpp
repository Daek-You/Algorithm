#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

class DoublePriorityQueue
{
public:
    vector<int> GetAnswer();
    void Operate(const char instruction, int data);
    bool IsEmpty() const { return _queue.empty(); }
private:
    multiset<int> _queue;
};

void DoublePriorityQueue::Operate(const char instruction, int data)
{
    switch (instruction)
    {
    case 'I':
        _queue.emplace(data);
        break;

    case 'D':
        if (IsEmpty())
            return;

        if (data == 1)
        {
            auto maxIter = _queue.end();
            _queue.erase(--maxIter);
        }

        else if (data == -1)
        {
            auto minIter = _queue.begin();
            _queue.erase(minIter);
        }
    }
}

vector<int> DoublePriorityQueue::GetAnswer()
{
    if (IsEmpty())
        return { 0, 0 };
    return { (*_queue.rbegin()), (*_queue.begin()) };
}

vector<int> solution(vector<string> operations) {
    DoublePriorityQueue dpQueue;

    for (const auto& operation : operations)
    {
        istringstream iss(operation);
        string instruction, data;
        iss >> instruction >> data;

        dpQueue.Operate(instruction[0], stoi(data));
    }

    return dpQueue.GetAnswer();
}