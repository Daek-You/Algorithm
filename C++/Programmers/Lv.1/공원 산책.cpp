#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
using Direction = pair<int, int>;
using Position  = pair<int, int>;

map<char, Direction> directions {{ 'N', Direction(-1, 0)},   // 북
                                 { 'S', Direction(1, 0) },   // 남
                                 { 'E', Direction(0, 1) },   // 동
                                 { 'W', Direction(0, -1)}    // 서
};


Position GetStartPosition(const vector<string>& park) {
    for (int row = 0; row < park.size(); row++)
        for (int col = 0; col < park[0].length(); col++)
            if (park[row][col] == 'S')
                return Position(row, col);

    return Position(-1, -1);
}


void ExecuteInstruction(const vector<string>& park, const Direction& direction, Position currentPosition, Position& originPosition, int distance) {
    int row = currentPosition.first;
    int col = currentPosition.second;

    if (row < 0 or row >= park.size() or col < 0 or col >= park[0].length() or park[row][col] == 'X')
        return;

    if (distance == 0) {
        originPosition = make_pair(row, col);
        return;
    }

    row += direction.first;
    col += direction.second;
    ExecuteInstruction(park, direction, make_pair(row, col), originPosition, distance - 1);
}


vector<int> solution(vector<string> park, vector<string> routes) {
    Position puppyRobotPositoin = GetStartPosition(park);

    for (const auto route : routes) {
        istringstream tokenizer(route);
        string bearing, moveDistance;

        tokenizer >> bearing >> moveDistance;

        Direction nextDirection = directions[bearing[0]];
        int distance = stoi(moveDistance);
        
        Position tempPosition = puppyRobotPositoin;
        ExecuteInstruction(park, nextDirection, tempPosition, puppyRobotPositoin, distance);
    }

    vector<int> answer {puppyRobotPositoin.first, puppyRobotPositoin.second};
    return answer;
}