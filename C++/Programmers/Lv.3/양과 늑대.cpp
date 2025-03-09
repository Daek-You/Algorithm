#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ROOT_NODE 0 
#define SHEEP 0
#define WOLF  1
#define ANIMAL_KIND 2

vector<vector<int>> BinaryTree;
vector<int> AnimalType;

void DFS(int node, int& answer, vector<int> animalCount, queue<int> nextNodes)
{
    animalCount[AnimalType[node]]++;

    if (animalCount[SHEEP] <= animalCount[WOLF])
        return;
    
    answer = max(answer, animalCount[SHEEP]);

    for (int child : BinaryTree[node])
        nextNodes.push(child);
    
    int N = nextNodes.size();

    for (int i = 0; i < N; i++)
    {
        int next = nextNodes.front();
        nextNodes.pop();

        DFS(next, answer, animalCount, nextNodes);
        nextNodes.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    BinaryTree.assign(info.size(), vector<int>());
    AnimalType.assign(info.begin(), info.end());

    for (const vector<int>& edge :edges)
    {
        int parent = edge[0], child = edge[1];
        BinaryTree[parent].push_back(child);
    }

    int answer = 0;
    queue<int> nextNodes;
    vector<int> animalCount(ANIMAL_KIND);

    DFS(ROOT_NODE, answer, animalCount, nextNodes);

    return answer;
}