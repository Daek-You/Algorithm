#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Edge = pair<int, int>;  // <중량, 노드>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N, MaxWeight, Source, Destination;
vector<vector<Edge>> Edges;
vector<bool> Visited;

void Initialize()
{
    int M;
    cin >> N >> M;

    Edges.resize(N + 1, vector<Edge>());
    Visited.resize(N + 1, false);

    while (M--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        Edges[from].push_back({weight, to});
        Edges[to].push_back({weight, from});
        MaxWeight = max(weight, MaxWeight);
    }

    cin >> Source >> Destination;
}

bool CanArrive(const int currentWeight)
{
    queue<int> nodes;
    nodes.push(Source);
    Visited[Source] = true;

    while (!nodes.empty())
    {
        int currentNode = nodes.front();
        nodes.pop();

        if (currentNode == Destination)
            return true;
        
        for (const Edge& next : Edges[currentNode])
        {
            int nextWeight = next.first, nextNode = next.second;

            if (Visited[nextNode] or nextWeight < currentWeight)
                continue;
            
            Visited[nextNode] = true;
            nodes.push(nextNode);
        }
    }

    return false;
}

int BinarySearch(int start, int last)
{
    while (start <= last)
    {
        int mid = (start + last) / 2;
        fill(Visited.begin(), Visited.end(), false);

        if (CanArrive(mid)) start = mid + 1;
        else                last = mid - 1;
    }

    return last;
}

int main()
{
    FAST_IO
    Initialize();

    int answer = BinarySearch(0, MaxWeight);
    cout << answer;
    return 0;
}