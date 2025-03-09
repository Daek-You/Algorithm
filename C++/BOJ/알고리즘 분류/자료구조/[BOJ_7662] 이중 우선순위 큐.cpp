#include <iostream>
#include <set>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

class DoublePriorityQueue
{
public:
    void Execute(const char instruction, const int data);
    const multiset<int>& GetElements() const { return elements; }

private:
    multiset<int> elements;
};

void DoublePriorityQueue::Execute(const char instruction, const int data)
{
    if (instruction == 'I')
    {
        elements.insert(data);
        return;
    }

    if (elements.empty())
        return;

    auto minIter = elements.begin();
    auto maxIter = elements.end();
    maxIter--;

    if (data == 1)
        elements.erase(maxIter);
    else if (data == -1)
        elements.erase(minIter);
}

int main()
{
    FAST_IO
        int numOfTestcases;
    cin >> numOfTestcases;

    while (numOfTestcases--)
    {
        int numOfInstructions;
        cin >> numOfInstructions;

        DoublePriorityQueue DPQueue;
        char instruction;
        int data;

        for (int i = 0; i < numOfInstructions; i++)
        {
            cin >> instruction >> data;
            DPQueue.Execute(instruction, data);
        }

        const multiset<int>& elements = DPQueue.GetElements();
        if (elements.empty())
        {
            cout << "EMPTY" << "\n";
            continue;
        }

        auto minIter = elements.begin();
        auto maxIter = elements.end();
        maxIter--;

        cout << *maxIter << " " << *minIter << "\n";
    }

    return 0;
}