#include <iostream>
#include <string>
using namespace std;

int main() {

    int num1, num2;
    cin >> num1 >> num2;

    string result = (num1 > num2) ? ">" : ((num1 == num2) ? "==" : "<");
    cout << result;
    return 0;
}