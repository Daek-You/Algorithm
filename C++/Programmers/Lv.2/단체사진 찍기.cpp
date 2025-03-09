#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const vector<char> friends{ 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
vector<bool> used(friends.size(), false);

struct Constraint
{
    Constraint() { }
    Constraint(char source, char target, char operator_, int distance) : _source(source), _target(target), _operator(operator_), _distance(distance) { }
    char _source;
    char _target;
    char _operator;
    int  _distance;
};

bool IsOk(int difference, int distance, char _operator)
{
    switch (_operator)
    {
    case '=':
        return difference == distance;
    case '<':
        return difference < distance;
    case '>':
        return difference > distance;
    }

    return false;
}

void DFS(const vector<Constraint>& constraints, vector<char>& sequence, int& answer)
{
    if (sequence.size() == friends.size())
    {
        bool isOk = true;

        for (const auto& constraint : constraints)
        {
            int sourceIndex = std::distance(sequence.begin(), std::find(sequence.begin(), sequence.end(), constraint._source));
            int targetIndex = std::distance(sequence.begin(), std::find(sequence.begin(), sequence.end(), constraint._target));
            int difference = abs(sourceIndex - targetIndex) - 1;

            if (!IsOk(difference, constraint._distance, constraint._operator))
            {
                isOk = false;
                break;
            }
        }

        if (isOk)
            answer++;
        return;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        if (used[i])
            continue;

        sequence.push_back(friends[i]);
        used[i] = true;

        DFS(constraints, sequence, answer);
        used[i] = false;
        sequence.pop_back();
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<Constraint> constrains;
    vector<char> sequence;

    for (const auto& constraint : data)
        constrains.emplace_back(Constraint(constraint[0], constraint[2], constraint[3], constraint[4] - '0'));

    DFS(constrains, sequence, answer);
    return answer;
}