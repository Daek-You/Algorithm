#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define TIME_UNIT   60

struct Assignment
{
    Assignment() { }
    Assignment(const string& name, int enterTime, int playTime) : name(name), enterTime(enterTime), playTime(playTime) { }
    bool operator<(const Assignment& other) const { return enterTime > other.enterTime; }

    string name;
    int enterTime, playTime;
};

priority_queue<Assignment> ReadyQueue;
stack<Assignment> WaitingAssignments;

int ConvertToIntegerMinute(const string& time)
{
    int hour = stoi(time.substr(0, 2)) * TIME_UNIT;
    int minute = stoi(time.substr(3, 2));
    return hour + minute;
}

vector<string> solution(vector<vector<string>> plans)
{
    // 1. 시간 순으로 과제를 할 수 있도록 우선순위 큐에 삽입
    for (const vector<string>& plan : plans)
    {
        string name = plan[0];
        int enterTime = ConvertToIntegerMinute(plan[1]);
        int playTime = stoi(plan[2]);
        ReadyQueue.push(Assignment(name, enterTime, playTime));
    }

    vector<string> answers;
    Assignment currentAssignment = ReadyQueue.top();
    ReadyQueue.pop();

    while (!ReadyQueue.empty())
    {
        Assignment nextAssignment = ReadyQueue.top();
        int nextAssignmentStartTime = nextAssignment.enterTime;
        int currentAssignmentFinishTime = currentAssignment.enterTime + currentAssignment.playTime;

        // 새 과제가 들어오기 전에 진행 중인 과제를 완료한 경우
        if (currentAssignmentFinishTime <= nextAssignmentStartTime)
        {
            answers.push_back(currentAssignment.name);

            // 진행 중인 과제가 끝난 시각이 새 과제 시작 시간과 같을 경우 (새 과제가 더 높은 우선순위를 가짐)
            if (currentAssignmentFinishTime == nextAssignmentStartTime)
            {
                currentAssignment = nextAssignment;
                ReadyQueue.pop();
            }

            // 새 과제 시작 시간보다 전에 진행 중인 과제가 끝날 경우 (멈춘 과제가 더 높은 우선순위를 가짐)
            else if (!WaitingAssignments.empty())
            {
                currentAssignment = WaitingAssignments.top();
                currentAssignment.enterTime = currentAssignmentFinishTime;
                WaitingAssignments.pop();
            }

            else
            {
                currentAssignment = nextAssignment;
                ReadyQueue.pop();
            }
        }

        // 진행 중인 과제를 완료하지 못한 경우
        else
        {
            int playTime = nextAssignmentStartTime - currentAssignment.enterTime;
            currentAssignment.playTime -= playTime;
            currentAssignment.enterTime = nextAssignmentStartTime;

            WaitingAssignments.push(currentAssignment);
            currentAssignment = nextAssignment;
            ReadyQueue.pop();
        }
    }

    answers.push_back(currentAssignment.name);
    while (!WaitingAssignments.empty())
    {
        answers.push_back(WaitingAssignments.top().name);
        WaitingAssignments.pop();
    }

    return answers;
}