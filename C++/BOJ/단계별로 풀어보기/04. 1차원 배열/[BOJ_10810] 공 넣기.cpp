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

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int basketSize, tryCount;
    cin >> basketSize >> tryCount;

    int* baskets = new int[basketSize] {0};

    for (int i = 0; i < tryCount; i++)
    {
        int begin, end, ballNumber;
        cin >> begin >> end >> ballNumber;

        for (int currentBasket = begin - 1; currentBasket < end; currentBasket++)
        {
            baskets[currentBasket] = ballNumber;
        }
    }

    Print(baskets, basketSize);
    return 0;
}