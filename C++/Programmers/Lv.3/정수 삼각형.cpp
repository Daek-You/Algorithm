#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int row = 1; row < triangle.size(); row++)
    {
        for (int col = 0; col < triangle[row].size(); col++)
        {
            int leftValue = (col > 0) ? triangle[row - 1][col - 1] : 0;
            int rightValue = (col < triangle[row - 1].size()) ? triangle[row - 1][col] : 0;
            triangle[row][col] += max(leftValue, rightValue);
        }
    }
    
    int lastRow = triangle.size() - 1;
    return *max_element(triangle[lastRow].begin(), triangle[lastRow].end());
}