#include <string>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;
const int MULTIPLY = 65536;
/* https://stackoverflow.com/questions/41782233/i-want-to-perform-a-multi-set-intersection-using-c */

multiset<string> CreateMultipleSet(const string& str) {
    multiset<string> result;
    int strLength = str.length() - 1;
    int extractionNum = 2;

    for (int i = 0; i < strLength; i++) {
        string element;
        bool isDiscardSet = false;

        for (int j = i; j < i + extractionNum; j++) {
            if (!isalpha(str[j])) {
                isDiscardSet = true;
                break;
            }

            element.push_back(tolower(str[j]));
        }

        if (!isDiscardSet)
            result.insert(element);
    }

    return result;
}

multiset<string> SetIntersection(const multiset<string>& set1, const multiset<string>& set2) {
    multiset<string> result;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

multiset<string> SetUnion(const multiset<string>& set1, const multiset<string>& set2) {
    multiset<string> result;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

int FindJaccardSimilarity(const multiset<string>& intersections, const multiset<string>& unions) {
    if (intersections.empty() and unions.empty())
        return 1 * MULTIPLY;
    return ((double)intersections.size() / unions.size()) * MULTIPLY;
}

int solution(string str1, string str2) {
    multiset<string> multiSet1 = CreateMultipleSet(str1);
    multiset<string> multiSet2 = CreateMultipleSet(str2);
    
    auto intersections = SetIntersection(multiSet1, multiSet2);
    auto unions = SetUnion(multiSet1, multiSet2);
    int answer = FindJaccardSimilarity(intersections, unions);
    return answer;
}