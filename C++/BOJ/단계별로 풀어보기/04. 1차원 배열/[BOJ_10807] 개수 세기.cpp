#include <iostream>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int arraySize;
    int* array;
    
    cin >> arraySize;
    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        int data;
        cin >> data;
        array[i] = data;
    }

    int findValue;
    cin >> findValue;
    int answer = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (findValue == array[i])
            answer++;
    }

    cout << answer;
}