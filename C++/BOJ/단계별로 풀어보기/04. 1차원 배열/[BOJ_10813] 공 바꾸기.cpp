#include <iostream>
using namespace std;


void Print(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i != size - 1)
            cout << " ";
    }
}

void Swap(int* array, int i, int j)
{
    int temp = array[i - 1];
    array[i - 1] = array[j - 1];
    array[j - 1] = temp;
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int basketSize, tryCount;
    cin >> basketSize >> tryCount;

    int* baskets = new int[basketSize];

    for (int i = 0; i < basketSize; i++)
        baskets[i] = i + 1;


    for (int i = 0; i < tryCount; i++)
    {
        int begin, end;
        cin >> begin >> end;
        Swap(baskets, begin, end);
    }

    Print(baskets, basketSize);
    return 0;
}