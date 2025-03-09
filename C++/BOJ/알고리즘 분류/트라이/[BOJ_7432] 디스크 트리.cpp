#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

struct Node
{
    ~Node()
    {
        for (pair<string, Node*> child : children)
            delete child.second;
        children.clear();
    }

    void Add(const vector<string>& directoryNames, int index)
    {
        if (index == directoryNames.size())
            return;

        auto iter = children.find(directoryNames[index]);
        if (iter == children.end())
        {
            Node* newNode = new Node();
            children.insert({ directoryNames[index], newNode });
            newNode->Add(directoryNames, index + 1);
            return;
        }

        iter->second->Add(directoryNames, index + 1);
    }

    void Print(int depth)
    {
        if (children.empty())
            return;

        for (const pair<string, Node*>& child : children)
        {
            cout << string(depth, ' ');
            cout << child.first << "\n";
            child.second->Print(depth + 1);
        }
    }

    map<string, Node*> children;
};

vector<string> Split(const string& path, const char delimiter)
{
    vector<string> directoryNames;
    istringstream tokenizer(path);
    string directoryName;

    while (getline(tokenizer, directoryName, delimiter))
        directoryNames.push_back(directoryName);
    return directoryNames;
}

Node* CreateTrie()
{
    int N;
    cin >> N;

    Node* root = new Node();
    while (N--)
    {
        string path;
        cin >> path;

        vector<string> directoryNames = Split(path, '\\');
        root->Add(directoryNames, 0);
    }

    return root;
}

int main()
{
    FAST_IO

    Node* root = CreateTrie();
    root->Print(0);

    delete root;
    return 0;
}
