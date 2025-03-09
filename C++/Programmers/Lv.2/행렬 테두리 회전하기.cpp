#include <vector>
#include <set>
using namespace std;
vector<vector<int>> GMatrix;

class RotatedArea {
public:
    RotatedArea(int x1, int y1, int x2, int y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2) 
    {
        int row = --x1, col = --y1;
        _buffer = GMatrix[row][col];

        // 1. 윗변 원소들 오른쪽으로 이동
        for (++col; col < y2; ++col)
            Swap(row, col);
        
        // 2. 오른변 원소들 아래쪽으로 이동
        for (++row, --col; row < x2; ++row)
            Swap(row, col);

        // 3. 아랫변 원소들 왼쪽으로 이동
        for (--row, --col; col >= y1; --col)
            Swap(row, col);

        // 4. 왼변 원소들 윗쪽으로 이동
        for (--row, ++col; row >= x1; --row)
            Swap(row, col);
    }

    int GetMinValue() { return *_elements.begin(); }
private:
    void Swap(int row, int col)
    {
        int currentValue = GMatrix[row][col];
        _elements.emplace(_buffer);
        GMatrix[row][col] = _buffer;
        _buffer = currentValue;
    }

public:
    int _buffer = 0;    // 회전시킬 때 이전 값을 저장해두는 임시 공간
    int _x1, _y1;
    int _x2 ,_y2;
private:
    set<int> _elements;
};


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 행렬 초기화
    for (int row = 0; row < rows; row++) {
        vector<int> currentRow(columns);

        for (int col = 0; col < columns; col++)
            currentRow[col] = row * columns + col + 1;
        GMatrix.emplace_back(currentRow);
    }

    
    for (const auto& query : queries) {
        int x1 = query[0], y1 = query[1];
        int x2 = query[2], y2 = query[3];
    
        RotatedArea area(x1, y1, x2, y2);
        answer.emplace_back(area.GetMinValue());
    }

    return answer;
}