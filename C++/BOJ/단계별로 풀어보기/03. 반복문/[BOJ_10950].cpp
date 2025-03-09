#include <iostream>
using namespace std;

int main(){
    int a, b, testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}