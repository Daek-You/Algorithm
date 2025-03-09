#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

struct Node
{
    Node(int N) : children(N, nullptr), isFinished(false), hasChild(false) { }
    ~Node()
    {
        for (Node* child : children)
            if (child != nullptr)
                delete child;
    }

    bool isFinished;
    bool hasChild;
    vector<Node*> children;
};

class Trie
{
public:
    Trie(int size, char startCharacter) : _size(size), _startCharacter(startCharacter)
    {
        _root = new Node(size);
    }
    ~Trie() { delete _root; }

    void Insert(const string& word);
    bool ContainsPrefixWord(const string& word) { return ContainsPrefixWord(word, _root, 0); }

private:
    bool ContainsPrefixWord(const string& word, Node* currentNode, int wordIndex);

private:
    const int     _size;
    const char    _startCharacter;
    Node* _root = nullptr;
};

void Trie::Insert(const string& word)
{
    Node* currentNode = _root;

    for (const char& character : word)
    {
        int index = character - _startCharacter;
        if (currentNode->children[index] == nullptr)
        {
            currentNode->children[index] = new Node(_size);
            currentNode->hasChild = true;
        }
        currentNode = currentNode->children[index];
    }

    currentNode->isFinished = true;
}

bool Trie::ContainsPrefixWord(const string& word, Node* currentNode, int wordIndex)
{
    // 끝까지 다 찾았는데, 현재 단어를 접두사로 가지는 더 긴 단어가 없는 경우
    if (wordIndex >= word.length() and !currentNode->hasChild)
        return false;

    // 끝까지 다 찾았는데, 현재 단어를 접두사로 가지는 더 긴 단어가 있는 경우
    if (wordIndex >= word.length() and currentNode->hasChild)
        return true;
    
    // 현재 단어보다 짧은 접두사 단어가 존재하는 경우
    if (currentNode->isFinished)
        return true;
    
    int index = word[wordIndex] - _startCharacter;
    return ContainsPrefixWord(word, currentNode->children[index], wordIndex + 1);
}

int main()
{
    FAST_IO
    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--)
    {
        int phoneNumberCount;
        cin >> phoneNumberCount;

        Trie trie(10, '0');
        vector<string> words(phoneNumberCount);

        for (int i = 0; i < phoneNumberCount; i++)
        {
            cin >> words[i];
            trie.Insert(words[i]);
        }

        bool isContainsPrefixWord = false;
        for (const string& word : words)
        {
            if (trie.ContainsPrefixWord(word))
            {
                cout << "NO" << "\n";
                isContainsPrefixWord = true;
                break;
            }
            
        }

        if (!isContainsPrefixWord)
            cout << "YES" << "\n";
    }

    return 0;
}