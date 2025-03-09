#include <string>
#include <vector>
using namespace std;
const int WOVEL_NUM = 5;
const char vowel[WOVEL_NUM] = { 'A', 'E', 'I', 'O', 'U' };
bool isFindingWord = false;

void CreateCombinationWords(const string& word, string targetWord, int& index)
{
    if (targetWord.length() == WOVEL_NUM)
        return;

    for (int i = 0; i < WOVEL_NUM; i++)
    {
        targetWord.push_back(vowel[i]);
        index++;
        if (targetWord.compare(word) == 0)
        {
            isFindingWord = true;
            break;
        }

        CreateCombinationWords(word, targetWord, index);
        if (isFindingWord)
            break;

        targetWord.pop_back();
    }
}

int GetWordIndex(const string& word)
{
    int index = 0;
    string targetWord = "";
    CreateCombinationWords(word, targetWord, index);
    return index;
}

int solution(string word) {
    return GetWordIndex(word);
}