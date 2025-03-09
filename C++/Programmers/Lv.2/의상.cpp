#include <string>
#include <vector>
#include <map>
using namespace std;
using ClothesCount = map<string, int>;

ClothesCount RegisterClothes(const vector<vector<string>>& clothes) {
    ClothesCount result;

    for (const auto clothesInfo : clothes) {
        string type = clothesInfo[1];
        result[type]++;
    }

    return result;
}

int FindCombination(const ClothesCount& clothes) {
    int count = 1;

    for (const auto clothesCount : clothes)
        count *= (clothesCount.second + 1);        // nC1 + nC0
    return count - 1;                              // 아무것도 안 입는 경우 제외
}


int solution(vector<vector<string>> clothes) {
    ClothesCount myClothes = RegisterClothes(clothes);
    int answer = FindCombination(myClothes);
    return answer;
}