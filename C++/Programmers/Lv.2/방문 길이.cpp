#include <string>
#include <vector>
#include <map>
using namespace std;
const int MAX_LENGTH = 11;

struct Point {
	Point() { }
	Point(int row, int col) : _row(row), _col(col) { }

	bool operator<(const Point& other) const {
		if (_row == other._row)
			return _col < other._col;
		return _row < other._row;
	}

	bool operator==(const Point& other) const {
		return _row == other._row and _col == other._col;
	}

	int _row;
	int _col;
};

map<char, Point> directions {  {'U', {-1, 0 }}, { 'D', {1, 0} }, { 'R', {0, 1} }, { 'L', {0, -1} }  };


class Record {
public:
	void Insert(const Point& otherStart, const Point& otherEnd) {
		auto iter = _lines.find(otherStart);
		
		/* 두 선분의 시작점이 같다면, 끝 점을 비교해본다. */
		if (iter != _lines.end()) {
			for (const auto myEndPoint : iter->second) {
				if (myEndPoint == otherEnd)
					return;
			}
		}

        // 점 A, B가 있다면 A-B, B-A는 같은 선분이므로 둘 다 추가
		_lines[otherStart].push_back(otherEnd);
		_lines[otherEnd].push_back(otherStart);
		_firstStepCount++;
	}

	int GetAnswer() { return _firstStepCount; }
private:
	map<Point, vector<Point>> _lines;    // <시작점, 끝 점들>
	int _firstStepCount = 0;
};


int solution(string dirs) {
	int firstStepCount = 0;
	int halfLine = MAX_LENGTH / 2;

	Point player(halfLine, halfLine);
	Record record;

	for (const auto instruction : dirs) {
	int nextRow = player._row + directions[instruction]._row;
	int nextCol = player._col + directions[instruction]._col;

	if (nextRow < 0 or nextRow >= MAX_LENGTH or nextCol < 0 or nextCol >= MAX_LENGTH)
		continue;

	Point start = player;
	Point end = player = Point(nextRow, nextCol);
	
	record.Insert(start, end);
	}

	return record.GetAnswer();
}