#include <map>
#include <string>
#include <vector>
using namespace std;
const int MAX_CRAFTING = 5;
const int DIAMOND_PICK_IDX = 0;
const int IRON_PICK_IDX = 1;
const int STONE_PICK_IDX = 2;


map<pair<int, string>, int> stressFatigues {
    {make_pair(DIAMOND_PICK_IDX, "diamond"), 1},    // 다이아 곡괭이, 다이아 광물
    {make_pair(DIAMOND_PICK_IDX, "iron"),    1},    // 다이아 곡괭이, 철 광물
    {make_pair(DIAMOND_PICK_IDX, "stone"),   1},    // 다이아 곡괭이, 돌 광물

    {make_pair(IRON_PICK_IDX, "diamond"),    5},    // 철 곡괭이, 다이아 광물
    {make_pair(IRON_PICK_IDX, "iron"),       1},    // 철 곡괭이, 철 광물
    {make_pair(IRON_PICK_IDX, "stone"),      1},    // 철 곡괭이, 돌 광물

    {make_pair(STONE_PICK_IDX, "diamond"),  25},    // 돌 곡괭이, 다이아 광물
    {make_pair(STONE_PICK_IDX, "iron"),      5},    // 돌 곡괭이, 철 광물
    {make_pair(STONE_PICK_IDX, "stone"),     1},    // 돌 곡괭이, 돌 광물
};

int CalculteStressFatigue(const int currentPick, const vector<string>& selectedMinerals) {
    int result = 0;

    for (int i = 0; i < selectedMinerals.size(); i++)
        result += stressFatigues[make_pair(currentPick, selectedMinerals[i])];
    return result;
}


void Function(vector<int>& picks, const vector<vector<string>>& splitMinerals, int currentIdx, int& sum, int& minValue) {
    bool isCompleteMining = true;
    
    for (int i = 0; i < picks.size(); i++) {
        if (picks[i] > 0 and currentIdx < splitMinerals.size()) {
            isCompleteMining = false;
            int totalStressFatigue = CalculteStressFatigue(i, splitMinerals[currentIdx]);
            picks[i]--;
            sum += totalStressFatigue;

            Function(picks, splitMinerals, currentIdx + 1, sum, minValue);

            sum -= totalStressFatigue;
            picks[i]++;
        }
    }

    if (isCompleteMining) {
        if (sum < minValue)
            minValue = sum;
    }
}

int FindMinStressFatigue(const vector<vector<string>>& splitMinerals, vector<int>& picks) {
    int sum = 0;
    int minValue = 2147483647;
    Function(picks, splitMinerals, 0, sum, minValue);
    
    return minValue;
}


vector<vector<string>> SplitMinerals(const vector<string>& originalMinerals) {
    vector<vector<string>> result;

    for (int i = 0; i < originalMinerals.size(); i += MAX_CRAFTING) {
        vector<string> minerals;

        for (int j = i; j < originalMinerals.size() and j < i + MAX_CRAFTING; j++)
            minerals.push_back(originalMinerals[j]);

        result.push_back(minerals);
    }

    return result;
}


int solution(vector<int> picks, vector<string> minerals) {
    vector<vector<string>> splitedMinerals = SplitMinerals(minerals);
    int answer = FindMinStressFatigue(splitedMinerals, picks);
    return answer;
}