#include <iostream>
#include <vector>
#include <string>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;
const char UNCOMPRESSIBLE = '?';

char IsAvailableCompress(const vector<string>& image, int N, int rowBegin, int colBegin)
{
    char color = '?';

    for (int row = rowBegin; row < rowBegin + N; row++)
    {
        for (int col = colBegin; col < colBegin + N; col++)
        {
            if (row == rowBegin and col == colBegin)
            {
                color = image[row][col];
                continue;
            }

            if (image[row][col] != color)
                return UNCOMPRESSIBLE;
        }
    }

    return color;
}

void Compress(const vector<string>& image, string& result, int N, int rowBegin, int colBegin)
{
    if (N == 1)
    {
        result += image[rowBegin][colBegin];
        return;
    }

    char flag = IsAvailableCompress(image, N, rowBegin, colBegin);
    
    if (flag != UNCOMPRESSIBLE)
    {
        result += flag;
        return;
    }

    result.push_back('(');
    N /= 2;

    Compress(image, result, N, rowBegin, colBegin);             // 왼쪽 위
    Compress(image, result, N, rowBegin, colBegin + N);         // 오른쪽 위
    Compress(image, result, N, rowBegin + N, colBegin);         // 왼쪽 아래
    Compress(image, result, N, rowBegin + N, colBegin + N);     // 오른쪽 아래

    result.push_back(')');
}


int main()
{
    FAST_IO
    int N;
    cin >> N;

    vector<string> bwImage(N);
    for (int i = 0; i < N; i++)
        cin >> bwImage[i];


    string answer = "";
    Compress(bwImage, answer, N, 0, 0);

    cout << answer;
    return 0;
}
