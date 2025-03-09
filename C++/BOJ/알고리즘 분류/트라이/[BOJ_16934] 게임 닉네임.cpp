#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define LOWER_ALPHABET_COUNT 26

struct Node
{
    Node() : children(LOWER_ALPHABET_COUNT, nullptr) {}
    bool isFinished = false;
    vector<Node*> children;
};

int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<string> aliases(N);
    unordered_map<string, int> numOfNickNames;
    Node* rootNode = new Node();

    for (int i = 0; i < N; i++)
    {
        string nickName;
        cin >> nickName;

        Node* currentNode = rootNode;
        bool isMakedAlias = false;
        string prefix = "";
        numOfNickNames[nickName]++;

        for (const char& element : nickName)
        {
            if (!isMakedAlias)
                prefix.push_back(element);

            int index = element - 'a';

            if (currentNode->children[index] == nullptr)
            {
                if (!isMakedAlias)
                {
                    aliases[i] = prefix;
                    isMakedAlias = true;
                }

                currentNode->children[index] = new Node();
            }

            currentNode = currentNode->children[index];
        }

        // 이전에 가입한 닉네임일 경우
        if (!isMakedAlias)
        {
            int count = numOfNickNames[nickName];

            if (count <= 1)
                aliases[i] = nickName;
            else
                aliases[i] = nickName + to_string(count);
        }
    }

    for (const string& answer : aliases)
        cout << answer << "\n";
    return 0;
}
