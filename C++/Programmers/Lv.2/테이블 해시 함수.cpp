#include <vector>
#include <algorithm>
using namespace std;
int column;

bool Compare(const vector<int>& tuple1, const vector<int>& tuple2) {
    if (tuple1[column - 1] == tuple2[column - 1])
        return tuple1[0] > tuple2[0];
    return tuple1[column - 1] < tuple2[column - 1];

}

int Moduler(const vector<int>& tuple, int moduler) {
    int sum = 0;
    for (const auto& element : tuple)
        sum += element % moduler;
    return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col;
    sort(data.begin(), data.end(), Compare);

    for (int i = row_begin - 1; i < row_end; i++) {
        int result = Moduler(data[i], i + 1);
        answer ^= result;
    }

    return answer;
}