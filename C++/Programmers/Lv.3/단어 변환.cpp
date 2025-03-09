#include <string>
#include <vector>
using namespace std;

bool IsDifferentOnlyOneCharacter(const string& source, const string& target)
{
    if (source.length() != target.length())
        return false;

    int differenceCount = 0;
    int N = source.length();

    for (int i = 0; i < N; i++)
    {
        if (source[i] != target[i])
            differenceCount++;

        if (differenceCount > 1)
            return false;
    }

    return true;
}

void DFS(string begin, const string& target, const vector<string>& words, vector<bool>& visited, int& answer, int step)
{
    if (answer <= step)
        return;

    if (begin == target)
    {
        answer = min(answer, step);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (!IsDifferentOnlyOneCharacter(words[i], begin) or visited[i])
            continue;

        visited[i] = true;
        DFS(words[i], target, words, visited, answer, step + 1);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int wordCount = words.size();
    int answer = wordCount + 1;
    vector<bool> visited(wordCount, false);

    DFS(begin, target, words, visited, answer, 0);
    return (answer == wordCount + 1) ? 0 : answer;
}