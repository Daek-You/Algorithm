#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Trie
{
public:
    Trie(int depth) : depth(depth) { }
    ~Trie();
    void Insert(const vector<string>& foodNames, int index);
    void Show();

private:
    int depth;
    map<string, Trie*> foods;
};

Trie::~Trie()
{
    for (auto& food : foods)
        if (food.second != nullptr)
            delete food.second;
}

void Trie::Insert(const vector<string>& foodNames, int index)
{
    if (index >= foodNames.size())
        return;
    
    auto findIt = foods.find(foodNames[index]);
    if (findIt == foods.end())
    {
        Trie* newFood = new Trie(depth + 1);
        foods.insert(make_pair(foodNames[index], newFood));
        newFood->Insert(foodNames, index + 1);
        return;
    }

    Trie* nextFood = findIt->second;
    nextFood->Insert(foodNames, index + 1);
}

void Trie::Show()
{
    string line(2 * depth, '-');
    for (const auto& food : foods)
    {
        cout << line << food.first << "\n";
        food.second->Show();
    }
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int numOfData;
    cin >> numOfData;
    
    Trie* root = new Trie(0);

    while (numOfData--)
    {
        int N;
        cin >> N;

        vector<string> foods(N);
        for (int i = 0; i < N; i++) cin >> foods[i];

        root->Insert(foods, 0);
    }

    root->Show();
    delete root;
    return 0;
}