#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int UNIT = 60;

int ConvertStringToMinuteInt(const string& time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return hour * UNIT + minute; 
}

string ConvertMinuteIntToString(const int& time) {
    int hour = time / UNIT;
    int minute = time % UNIT;

    string strHour = to_string(hour);
    if (strHour.length() < 2)
        strHour.insert(0, "0");
    
    string strMinute = to_string(minute);
    if (strMinute.length() < 2)
        strMinute.insert(0, "0");

    string result = strHour + ":" + strMinute;
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int N = timetable.size();
    multiset<int> intTimes;

    for (int i = 0; i < N; i++)
        intTimes.emplace(ConvertStringToMinuteInt(timetable[i]));

    int busTime = 9 * UNIT;
    int runCount = 0;

    vector<int> answers;

    while (runCount < n) {
        int passengerCount = 0;
        int lastPassengerTime = 0;

        while (!intTimes.empty() and *intTimes.begin() <= busTime) {
            passengerCount++;
            lastPassengerTime = *intTimes.begin();
            intTimes.erase(intTimes.begin());

            if (passengerCount == m)
                break;
        }

        int boardingTime = (passengerCount < m) ? busTime : lastPassengerTime - 1;
        answers.emplace_back(boardingTime);

        busTime += t;
        runCount++;
    }

    sort(answers.begin(), answers.end(), greater<int>());
    return ConvertMinuteIntToString(answers[0]);
}