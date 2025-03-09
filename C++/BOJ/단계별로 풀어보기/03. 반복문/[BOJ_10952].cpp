#include <iostream>
using namespace std;

int main(void) {
    int A, B;

    while (true) {
        cin >> A >> B;

        if (!A && !B)
            break;
        cout << A + B << "\n";
    }
    return 0;
}