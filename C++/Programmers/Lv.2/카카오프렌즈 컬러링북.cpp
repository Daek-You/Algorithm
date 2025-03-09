#include <vector>
#include <queue>
using namespace std;
const int DIRECTION_COUNT = 4;
const int rowDirections[DIRECTION_COUNT] = { -1, 1, 0, 0 };
const int colDirections[DIRECTION_COUNT] = { 0, 0, -1, 1 };

struct Pixel {
    Pixel() { }
    Pixel(int color, int row, int col) : _color(color), _row(row), _col(col) { }

    int     _color;
    int     _row;
    int     _col;
};

int FindArea(vector<vector<Pixel>>& board, vector<vector<bool>>& visited, int m, int n, Pixel selection) {
    int area = 1;
    visited[selection._row][selection._col] = true;
    
    queue<Pixel> coloredAreas;
    coloredAreas.emplace(selection);

    while (!coloredAreas.empty()) {
        Pixel pixel = coloredAreas.front();
        coloredAreas.pop();

        for (int i = 0; i < DIRECTION_COUNT; i++) {
            int nextRow = pixel._row + rowDirections[i];
            int nextCol = pixel._col + colDirections[i];

            if (nextRow < 0 or nextRow >= m or nextCol < 0 or nextCol >= n)
                continue;
            if (board[nextRow][nextCol]._color != pixel._color or board[nextRow][nextCol]._color == 0 or visited[nextRow][nextCol])
                continue;

            coloredAreas.emplace(Pixel(pixel._color, nextRow, nextCol));
            visited[nextRow][nextCol] = true;
            area++;
        }
    }

    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<Pixel>> board(m, vector<Pixel>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int row = 0; row < m; row++)
        for (int col = 0; col < n; col++)
            board[row][col] = Pixel(picture[row][col], row, col);

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (visited[row][col] or board[row][col]._color == 0)
                continue;

            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, FindArea(board, visited, m, n, board[row][col]));
        }
    }

    return { number_of_area, max_size_of_one_area };
}