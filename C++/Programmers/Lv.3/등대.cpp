#include <vector>
using namespace std;

vector<vector<int>> Nodes;
vector<bool> OnLight;

void DFS(int currentNode, int parentNode, int& answer)
{
    for (const int childNode : Nodes[currentNode])
    {
        if (childNode == parentNode)    continue;

        DFS(childNode, currentNode, answer);

        if (!OnLight[childNode] and !OnLight[currentNode])
        {
            OnLight[currentNode] = true;
            answer++;
        }
    }
}


int solution(int n, vector<vector<int>> lighthouse)
{
    Nodes.resize(n + 1);
    OnLight.resize(n + 1, false);

    for (const vector<int>& link : lighthouse)
    {
        int from = link[0], to = link[1];
        Nodes[from].push_back(to);
        Nodes[to].push_back(from);
    }

    int answer = 0;
    DFS(1, 1, answer);
    return answer;
}