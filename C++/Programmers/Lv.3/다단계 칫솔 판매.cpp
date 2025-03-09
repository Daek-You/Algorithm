#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
#define PRICE_OF_A_TOOTHBRUSH 100

unordered_map<string, int> PeopleIndex;

void PayFee(const vector<string>& enroll, const vector<string>& referral, vector<int>& answer, string recommendedPerson, int profit)
{
    int recommendedPersonIndex = PeopleIndex[recommendedPerson];
    int fee = profit / 10;
    answer[recommendedPersonIndex] += (profit - fee);

    string recommendator = referral[recommendedPersonIndex];
    while (recommendator != "-" and fee > 0)
    {
        profit = fee;
        fee /= 10;

        recommendedPersonIndex = PeopleIndex[recommendator];
        answer[recommendedPersonIndex] += (profit - fee);
        recommendator = referral[recommendedPersonIndex];
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    // 각 사람이 배열 내에 어디 인덱스에 있는지 정보 저장
    for (int i = 0; i < enroll.size(); i++)
        PeopleIndex.emplace(enroll[i], i);
    
    vector<int> answer(enroll.size(), 0);
    for (int i = 0; i < seller.size(); i++)
    {
        int profit = amount[i] * PRICE_OF_A_TOOTHBRUSH;  // 판매 이익
        PayFee(enroll, referral, answer, seller[i], profit);
    }

    return answer;
}