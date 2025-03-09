#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> youngerBrotherToppings;
    youngerBrotherToppings.reserve(topping.size());

    for (const auto i : topping)
        youngerBrotherToppings[i]++;

    unordered_set<int> olderBrotherToppings;
    olderBrotherToppings.reserve(topping.size());

    for (int i = 0; i < topping.size(); i++) {
        olderBrotherToppings.insert(topping[i]);
        auto toppingIt = youngerBrotherToppings.find(topping[i]);

        if (toppingIt == youngerBrotherToppings.end())
            continue;

        if (toppingIt->second > 0) {
            toppingIt->second--;

            if(toppingIt->second == 0)
                youngerBrotherToppings.erase(topping[i]);
        }

        if (olderBrotherToppings.size() == youngerBrotherToppings.size())
            answer++;
    }

    return answer;
}