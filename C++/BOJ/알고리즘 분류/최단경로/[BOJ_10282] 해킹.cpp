#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Dependence = pair<int, int>;  // <time, destination>

#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1000000000

vector<int> Dijkstra(const vector<vector<Dependence>>& graph, int start)
{
    vector<int> times(graph.size(), INF);
    priority_queue<Dependence, vector<Dependence>, greater<Dependence>> networks;

    times[start] = 0;
    networks.emplace(Dependence(0, start));

    while (!networks.empty())
    {
        int time = networks.top().first;
        int id = networks.top().second;
        networks.pop();

        if (times[id] < time)
            continue;

        for (const Dependence& otherNetwork : graph[id])
        {
            int newTime = time + otherNetwork.first;
            int otherId = otherNetwork.second;

            if (newTime < times[otherId])
            {
                times[otherId] = newTime;
                networks.emplace(Dependence(newTime, otherId));
            }
        }
    }

    int computerNum = 0, lastTime = 0;
    for (int i = 1; i < times.size(); i++)
    {
        if (times[i] != INF)
        {
            computerNum++;
            lastTime = max(lastTime, times[i]);
        }
    }

    return { computerNum, lastTime };
}


int main()
{
    FAST_IO
    int T, N, D, C;
    cin >> T;

    while (T--)
    {
        cin >> N >> D >> C;
        vector<vector<Dependence>> dependences(N + 1, vector<Dependence>());
        int to, from, time;

        for (int i = 0; i < D; i++)
        {
            cin >> to >> from >> time;
            dependences[from].emplace_back(Dependence(time, to));
        }

        vector<int> answer = Dijkstra(dependences, C);
        cout << answer[0] << " " << answer[1] << "\n";
    }

    return 0;
}