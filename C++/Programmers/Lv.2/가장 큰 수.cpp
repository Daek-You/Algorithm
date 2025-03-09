#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MULTIPLY = 3;

class Data {
public:
    Data() { }
    Data(int num) {
        originNumber = to_string(num);
        for (int i = 0; i < MULTIPLY; i++)
            convertedNumber += originNumber;
    }

    bool operator<(const Data& other) {
        for (int i = 0; i < convertedNumber.length() and i < other.convertedNumber.length(); i++) {
            if (convertedNumber[i] == other.convertedNumber[i])
                continue;
            return convertedNumber[i] > other.convertedNumber[i];
        }

        if (convertedNumber.length() == other.convertedNumber.length())
            return false;
        return convertedNumber.length() < other.convertedNumber.length();
    }
    
public:
    string originNumber;
    string convertedNumber;
};

string solution(vector<int> numbers) {
    vector<Data> myData;
    bool isZero = true;

    for (const auto element : numbers) {
        if (element != 0 and isZero) {
            myData.emplace_back(Data(element));
            isZero = false;
            continue;
        }

        myData.emplace_back(Data(element));
    }

    if (isZero)
        return "0";

    sort(myData.begin(), myData.end());
    string answer = "";

    for (const auto element : myData)
        answer += element.originNumber;
    return answer;
}