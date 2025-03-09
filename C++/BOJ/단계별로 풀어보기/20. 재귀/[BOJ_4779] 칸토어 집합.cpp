#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* 재귀에 약한 것 같다. 재귀를 많이 풀어보자. */

//void ApproximateCantorSet(string& cantorSet, int N)
//{
//    if (N == 0)
//    {
//        cout << '-';
//        return;
//    }
//
//    ApproximateCantorSet(cantorSet, N - 1);
//
//    for (int i = 0; i < pow(3, N - 1); i++)
//        cout << " ";
//
//    ApproximateCantorSet(cantorSet, N - 1);
//}

void ApproximateCantorSet(string& cantorSet, int start, int end)
{
    if (end - start == 1)
        return;

    int mid = (end - start) / 3;
    for (int i = start + mid; i < end - mid; i++)
        cantorSet[i] = ' ';

    ApproximateCantorSet(cantorSet, start, start + mid);
    ApproximateCantorSet(cantorSet, end - mid, end);
}


int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    while (cin >> N)
    {
        int totalNum = static_cast<int>(pow(3, N));
        string cantorSet(totalNum, '-');

        ApproximateCantorSet(cantorSet, 0, totalNum);
        cout << cantorSet << '\n';
    }
    return 0;
}