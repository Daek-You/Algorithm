#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define MAX 1000000

int main()
{
    FAST_IO
    int N, height, answer = 0;
    cin >> N;

    vector<int> arrows(MAX + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> height;

        if (arrows[height + 1] > 0)
            arrows[height + 1]--, arrows[height]++;
        else
            answer++, arrows[height]++;
    }

    cout << answer;

    return 0;
}