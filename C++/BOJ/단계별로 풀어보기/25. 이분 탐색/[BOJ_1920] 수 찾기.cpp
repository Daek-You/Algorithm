#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int main()
{
    FAST_IO;

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int key;
        cin >> key;
        cout << binary_search(arr.begin(), arr.end(), key) << "\n";
    }

    return 0;
}
