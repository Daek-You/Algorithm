#include <string>
#include <vector>
using namespace std;
using User = vector<vector<int>>;
vector<int> discountRates = { 40, 30, 20, 10 };

struct Emoticon {
    Emoticon() { }
    Emoticon(int originalPrice, int discountRate) : _discountRate(discountRate) {
        _price = originalPrice * (1.0f - (static_cast<float>(discountRate) * 0.01f));
    }

    int _price;
    int _discountRate;
};

void Search(const User& users, const vector<int>& emoticons, vector<Emoticon>& discountedEmoticons, vector<int>& answers, int emoticonIdx) {
    if (discountedEmoticons.size() == emoticons.size()) {
        int totalBuyingPrice = 0;
        int member = 0;

        for (const auto& user : users) {
            int requireDiscountRate = user[0];
            int membershipStandardPrice = user[1];
            int buying = 0;

            for (const auto& emoticon : discountedEmoticons) {
                if (emoticon._discountRate < requireDiscountRate)
                    continue;

                buying += emoticon._price;

                if (buying >= membershipStandardPrice) {
                    member++;
                    break;
                }
            }

            totalBuyingPrice += (buying < membershipStandardPrice) ? buying : 0;
        }

        if (answers[0] == member and answers[1] < totalBuyingPrice)
            answers[1] = totalBuyingPrice;

        else if (answers[0] < member) {
            answers[0] = member;
            answers[1] = totalBuyingPrice;
        }

        return;
    }

    for (int ei = emoticonIdx; ei < emoticons.size(); ei++) {
        for (int di = 0; di < discountRates.size(); di++) {
            discountedEmoticons.emplace_back(Emoticon(emoticons[ei], discountRates[di]));
            Search(users, emoticons, discountedEmoticons, answers, ei + 1);
            discountedEmoticons.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answers { 0, 0 };
    vector<Emoticon> discountedEmoticons;
    
    Search(users, emoticons, discountedEmoticons, answers, 0);
    return answers;
}
