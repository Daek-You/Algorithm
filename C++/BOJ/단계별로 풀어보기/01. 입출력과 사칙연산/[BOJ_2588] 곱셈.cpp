#include <iostream>
#include <string>
using namespace std;

int main() {
    int upperNum, lowerNum;
    cin >> upperNum >> lowerNum;

    int num3 = upperNum * (lowerNum % 10);
    int num4 = upperNum * ((lowerNum / 10) % 10);
    int num5 = upperNum * ((lowerNum / 100));
    int num6 = num3 + num4 * 10 + num5 * 100;

    cout << num3 << endl;
    cout << num4 << endl;
    cout << num5 << endl;
    cout << num6 << endl;
    return 0;
}