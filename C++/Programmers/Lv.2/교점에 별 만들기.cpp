#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAP_OUTRANGE = 1001;
/*
      limits 헤더가 적용 안 되나보다.
      LLONG_MAX = 9223372036854775807
*/

/* 서로 다른 두 직선을 받아, 교점을 찾아봅시다. */
pair<long long, long long> FindIntegerIntersection(const vector<int> line1, const vector<int> line2)
{
    long long size = line1.size();                                           // line1과 line2 둘 다 3개씩이므로, 둘 중 하나만 사이즈로 받아도 됩니다.
    long long denominator = (line1[0] * line2[1]) - (line1[1] * line2[0]);   // 분모를 구해봅시다. (A*D - B*C)

    if (denominator == 0)
        return pair<int, int>(MAP_OUTRANGE, MAP_OUTRANGE);

    // (B*F - E*D) / denominator
    double intersectionX = ((long long)line1[1] * (long long)line2[2] - (long long)line1[2] * (long long)line2[1]) / static_cast<double>(denominator);
    
    // (E*C - A*F) / denominator
    double intersectionY = ((long long)line1[2] * (long long)line2[0] - (long long)line1[0] * (long long)line2[2]) / static_cast<double>(denominator);

    bool isDoubleNumber = intersectionX - static_cast<long long>(intersectionX) != 0 ||
        intersectionY - static_cast<long long>(intersectionY) != 0;

    if (isDoubleNumber)
        return pair<int, int>(MAP_OUTRANGE, MAP_OUTRANGE);
    return pair<long long, long long>(intersectionX, intersectionY);
}


/* 재귀 함수를 이용하여 조합의 수를 구해봅시다. */
void CombinationWithDFS(const vector<vector<int>>& lines, vector<vector<vector<int>>>& result, vector<vector<int>>& createdCombination, int currentIdx, int r)
{
    if (createdCombination.size() == r)
    {
        result.push_back(createdCombination);
        return;
    }

    int lastIdx = (createdCombination.size() == 0) ? -1 : currentIdx;

    for (int i = lastIdx + 1; i < lines.size(); i++)
    {
        createdCombination.push_back(lines[i]);
        CombinationWithDFS(lines, result, createdCombination, i, r);
        createdCombination.pop_back();
    }
}


/* 조합(Combination)으로 직선들 중 r개를 선택해봅시다.*/
vector<vector<vector<int>>>& GetCombination(const vector<vector<int>>& lines, const int r)
{
    auto* results = new vector<vector<vector<int>>>();
    vector<vector<int>> createdCombination;
    CombinationWithDFS(lines, *results, createdCombination, 0, r);

    return *results;
}


vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    set<pair<long long, long long>> intersections;

    long long minX = 9223372036854775807;
    long long maxX = -9223372036854775807;
    long long minY = 9223372036854775807;
    long long maxY = -9223372036854775807;


    auto combinationLines = GetCombination(line, 2);

    for (const auto lines : combinationLines)
    {
        vector<int> line1 = lines[0];
        vector<int> line2 = lines[1];
        pair<long long, long long> intersection = FindIntegerIntersection(line1, line2);

        // 교점이 있을 경우 추가
        if (intersection.first != MAP_OUTRANGE && intersection.second != MAP_OUTRANGE)
        {
            intersections.insert({ intersection.first, intersection.second });
        }
    }


    // 상하좌우 최소, 최대 범위 구하기
    for (const auto intersection : intersections)
    {
        minX = min(intersection.first, minX);
        maxX = max(intersection.first, maxX);
        minY = min(intersection.second, minY);
        maxY = max(intersection.second, maxY);
    }

    long long width = maxX - minX + 1;
    long long height = maxY - minY + 1;

    for (long long i = 0; i < height; i++)
    {
        string row(width, '.');
        answer.push_back(row);
    }


    for (const auto intersection : intersections)
    {
        long long column = maxY - intersection.second;
        long long row = intersection.first - minX;
        answer[column][row] = '*';
    }

    return answer;
}