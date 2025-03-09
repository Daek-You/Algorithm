#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
using TimeLine = pair<int, int>;

#define TIME_UNIT 60
#define HYPHEN_INDEX 8

int ConvertToSeconds(const string& time)
{
    int seconds = 0, exp = 2;
    istringstream tokenizer(time);
    string buffer;

    while (getline(tokenizer, buffer, ':'))
        seconds += stoi(buffer) * static_cast<int>(pow(TIME_UNIT, exp--));
    return seconds;
}

string ConvertToString(int seconds)
{
    string hour = to_string(seconds / (TIME_UNIT * TIME_UNIT));
    seconds %= (TIME_UNIT * TIME_UNIT);

    string minute = to_string(seconds / TIME_UNIT);
    string second = to_string(seconds % TIME_UNIT);

    if (hour.length() < 2)      hour.insert(0, "0");
    if (minute.length() < 2)    minute.insert(0, "0");
    if (second.length() < 2)    second.insert(0, "0");

    return hour + ":" + minute + ":" + second;
}


string solution(string play_time, string adv_time, vector<string> logs)
{
    int playTime = ConvertToSeconds(play_time);
    int advertisingTime = ConvertToSeconds(adv_time);

    vector<int> times(360000, 0);
    for (const string& log : logs)
    {
        int startTime = ConvertToSeconds(log.substr(0, HYPHEN_INDEX));
        int endTime = ConvertToSeconds(log.substr(HYPHEN_INDEX + 1));

        for (int i = startTime; i < endTime; i++)
            times[i]++;
    }

    long long sum = 0, maxTime = 0, answer = 0;
    for (int i = 0; i < advertisingTime; i++)
        sum += times[i];
    maxTime = sum;

    for (int i = advertisingTime; i < playTime; i++)
    {
        sum = sum - times[i - advertisingTime] + times[i];

        if (maxTime < sum)
        {
            maxTime = sum;
            answer = i - advertisingTime + 1;
        }
    }

    return ConvertToString(answer);
}