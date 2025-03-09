#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;

int DotProduct(const vector<int>& vec1, const vector<int>& vec2) {
    int sum = 0;
    for (int i = 0; i < vec1.size(); i++)
        sum += (vec1[i] * vec2[i]);
    return sum;
}

Matrix TransposedMatrix(const Matrix& originMatrix) {
    /*
        내적 계산을 쉽게 하기 위해, 다음처럼 바꾸는 변환 과정 진행
        1 4        1 2 3
        2 5    ->  4 5 6
        3 6
    */

    Matrix result;
    int originRow = originMatrix.size();
    int originCol = originMatrix[0].size();

    // 열 방향으로 읽기
    for (int c = 0; c < originCol; c++) {
        vector<int> row;

        for (int r = 0; r < originRow; r++)
            row.push_back(originMatrix[r][c]);
        result.push_back(row);
    }

    return result;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    Matrix answer;
    Matrix transposedArr2 = TransposedMatrix(arr2);

    for (int a1i = 0; a1i < arr1.size(); a1i++) {
        vector<int> row;

        for (int a2i = 0; a2i < transposedArr2.size(); a2i++) {
            int sum = DotProduct(arr1[a1i], transposedArr2[a2i]);
            row.push_back(sum);
        }

        answer.push_back(row);
    }

    return answer;
}