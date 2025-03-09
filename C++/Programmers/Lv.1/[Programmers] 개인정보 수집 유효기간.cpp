#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Date
{
public:
    Date(string date, char delimiter)
    {
        istringstream iss(date);
        string buffer;
        int intDate[3];  // 년, 월, 일
        int i = 0;

        while (getline(iss, buffer, delimiter))
        {
            intDate[i] = stoi(buffer);
            i++;
        }

        // 년, 월, 일을 모두 일(day)로 변환하여 저장
        _convertedDays = intDate[0] * MAX_MONTHS * MAX_DAYS + intDate[1] * MAX_DAYS + intDate[2];
    }

    Date(const int convertedDays)           { _convertedDays = convertedDays; }
    Date(const Date& otherDate)             { this->_convertedDays = otherDate._convertedDays; }
    bool operator<=(const Date& otherDate)  { return _convertedDays <= otherDate._convertedDays; }
    Date& operator=(const Date& otherDate) {
        this->_convertedDays = otherDate._convertedDays;
        return *this;
    }

    Date operator+(const int month) { 
        Date date(_convertedDays + month * MAX_DAYS);
        return date;
    }

private:
    const int MAX_MONTHS = 12;
    const int MAX_DAYS = 28;
    int _convertedDays;
};

class PersonalInformation
{
public:
    PersonalInformation(int id, Date collectionDate, int expirationMonth) : _id(id), _collectionDate(collectionDate),
        _expirationMonth(expirationMonth) { }

    bool IsTermExpired(const Date& today) {
        Date expiredDate =  _collectionDate + _expirationMonth;
        return expiredDate <= today;
    }

    int GetId() { return _id; }
private:
    int _id;               // 번호
    Date _collectionDate;  // 개인정보 수집 일자
    int _expirationMonth;  // 유효 달 수
};


pair<string, string> Split(const string& str)
{
    istringstream iss(str);
    string str1, str2;
    iss >> str1 >> str2;

    return make_pair(str1, str2);
}

void RegisterTerm(map<char, int>& termTypes, const string& term)
{
    auto termAndMonth = Split(term);
    termTypes[termAndMonth.first[0]] = stoi(termAndMonth.second);
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    Date Today(today, '.');
    map<char, int> termTypes;
    vector<int> answer;

    for (const auto term : terms)
        RegisterTerm(termTypes, term);

    for (int i = 0; i < privacies.size(); i++)
    {
        auto dateAndTerm = Split(privacies[i]);
        Date date(dateAndTerm.first, '.');
        PersonalInformation info(i + 1, date, termTypes[dateAndTerm.second[0]]);

        if (info.IsTermExpired(Today))
            answer.push_back(info.GetId());
    }

    return answer;
}