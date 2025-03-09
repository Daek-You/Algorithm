#include <iostream>
#include <vector>
using namespace std;
int currentSaveCount;
int answer;

void Merge(vector<int>* original, vector<int>* temp, int left, int right, int K)
{
    int mid = (left + right) / 2;
    int L = left, R = mid + 1, i = left;

    /* 좌우 중 작은 것부터 temp 임시 배열에 차곡차곡 쌓는다. */
    while (L <= mid and R <= right)
    {
        (*temp)[i++] = ((*original)[L] <= (*original)[R]) ? (*original)[L++] : (*original)[R++];
        currentSaveCount++;

        if (currentSaveCount == K)
            answer = (*temp)[i - 1];
    }
    // -----------------------------------------------------------------------------

    /* 다 채우고 나면, 남는 부분들을 temp 임시 배열에 담는다.*/
    bool isRightLeft = L > mid;
    int start = isRightLeft ? R : L;
    int last = isRightLeft ? right : mid;

    for (; start <= last; start++)
    {
        (*temp)[i++] = (*original)[start];
        currentSaveCount++;

        if (currentSaveCount == K)
            answer = (*temp)[i - 1];
    }
    // -----------------------------------------------------------------------------

    /* temp 배열에 담았던 걸 원본 배열 original에 다시 옮긴다. */
    for (int j = left; j <= right; j++)
        (*original)[j] = (*temp)[j];
}

void MergeSort(vector<int>* original, vector<int>* temp, int left, int right, int K)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        MergeSort(original, temp, left, middle, K);        // 전반부 정렬
        MergeSort(original, temp, middle + 1, right, K);   // 후반후 정렬
        Merge(original, temp, left, right, K);             // 병합
    }
}


int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int>* originalArray = new vector<int>(N);
    vector<int>* temp = new vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        (*originalArray)[i] = data;
    }

    MergeSort(originalArray, temp, 0, N - 1, K);
    
    if (currentSaveCount < K)
        cout << -1;
    else
        cout << answer;
    
    delete originalArray;
    delete temp;
    return 0;
}