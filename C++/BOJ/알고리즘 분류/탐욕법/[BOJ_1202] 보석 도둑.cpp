#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

struct Gem
{
    Gem() { }
    Gem(int weight, int price) : weight(weight), price(price) { }
    int weight, price;
};

int main()
{
    FAST_IO
    int N, K;
    cin >> N >> K;

    vector<Gem> gems(N);
    int weight, price;
    for (int i = 0; i < N; i++)
    {
        cin >> weight >> price;
        gems[i].weight = weight;
        gems[i].price = price;
    }
    
    vector<int> bags(K);
    long long maxWeight;
    for (int i = 0; i < K; i++)
    {
        cin >> maxWeight;
        bags[i] = maxWeight;
    }

    sort(gems.begin(), gems.end(), [](const Gem& g1, const Gem& g2) { return g1.weight < g2.weight; });
    sort(bags.begin(), bags.end());

    priority_queue<int> expensiveOrderGems;
    int gemIdx = 0;
    long long maxGemPrice = 0;

    for (int bagIdx = 0; bagIdx < K; bagIdx++)
    {
        while (gemIdx < N and gems[gemIdx].weight <= bags[bagIdx])
            expensiveOrderGems.emplace(gems[gemIdx++].price);
        
        if (expensiveOrderGems.empty())
            continue;
        maxGemPrice += expensiveOrderGems.top();
        expensiveOrderGems.pop();
    }

    cout << maxGemPrice;
    return 0;
}