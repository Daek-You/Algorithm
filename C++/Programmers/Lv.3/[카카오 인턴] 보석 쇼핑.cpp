#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    // 1. 보석 종류 및 개수 세기
    int N = gems.size();
    map<string, int> counts;
    for (const string& gem : gems)
        counts[gem]++;

    int gemKind = counts.size();
    counts.clear();

    // 2. 모든 종류의 보석을 포함하는 구간을 찾으며 갱신하기
    int range = N;
    int start = 0, end = 0;
    vector<int> answer(2);

    while (true)
    {
        if (counts.size() != gemKind and end < N)
        {
            counts[gems[end++]]++;
            continue;
        }

        if (start > end or counts.size() != gemKind)
            break;

        counts[gems[start]]--;
        if (counts[gems[start]] == 0)
            counts.erase(gems[start]);
        start++;

		if (end - start < range)
		{
			range = end - start;
			answer[0] = start;
			answer[1] = end;
		}
    }

    return answer;
}