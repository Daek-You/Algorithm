#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<string> Answers;

bool IsPrimeNumber(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

void CreateAmazingPrimeNumber(string& number, const int N)
{
    if (number.length() == N)
    {
        Answers.push_back(number);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        number.push_back(i + '0');
        if (IsPrimeNumber(stoi(number))) CreateAmazingPrimeNumber(number, N);
        number.pop_back();
    }
}


int main()
{
    FAST_IO
    int N;
    cin >> N;

    string number = "";
    CreateAmazingPrimeNumber(number, N);

    for (const string& answer : Answers)
        cout << answer << "\n";
    return 0;
}