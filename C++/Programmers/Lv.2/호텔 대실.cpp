#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
const int MINUTE_UNIT = 60;

/*
    - 최소한의 객실만 사용하여 예약 손님을 받고 싶음
    - 한 번 사용한 객실은 퇴실 시간 기준, 10분간 청소한 후에 다음 손님 받는 것이 가능
    - 필요한 최소 객실의 수를 구하라.
*/

/*
    분으로 환산하여 계산하자. 그게 편할 듯

*/

int GetConvertedMinute(string time, char delimiter)
{
    int result = 0;
    istringstream iss(time);
    string buffer;
    bool isHour = true;

    while (getline(iss, buffer, delimiter))
    {
        if (isHour)
        {
            result += stoi(buffer) * MINUTE_UNIT;
            isHour = false;
            continue;
        }

        result += stoi(buffer);
    }

    return result;
}


int solution(vector<vector<string>> book_time) {
    if (book_time.size() == 1)
        return 1;

    const int CLEAN_TIME = 10;
    vector<pair<int, int>> times;
    
    for (const auto timeVector : book_time)
    {
        int hiredRoomStartTime = GetConvertedMinute(timeVector[0], ':');
        int hiredRoomEndTime = GetConvertedMinute(timeVector[1], ':');
        times.push_back(make_pair(hiredRoomStartTime, hiredRoomEndTime));
    }

    sort(times.begin(), times.end());
    
    vector<vector<pair<int, int>>> rooms;
    vector<pair<int, int>> hiredRoomTime { times[0] };
    rooms.push_back(hiredRoomTime);

    for (int ci = 1; ci < times.size(); ci++)
    {
        int currentStartTime = times[ci].first;
        int currentEndTime = times[ci].second;
        bool isNeedingMoreRoom = true;

        for (int ri = 0; ri < rooms.size(); ri++)
        {
            auto checkRoom = rooms[ri];
            auto lastTime = checkRoom[checkRoom.size() - 1];

			if ((lastTime.first - CLEAN_TIME >= currentEndTime) or lastTime.second + CLEAN_TIME <= currentStartTime)
			{
				rooms[ri].push_back(make_pair(currentStartTime, currentEndTime));
				sort(rooms[ri].begin(), rooms[ri].end());
				isNeedingMoreRoom = false;
				break;
			}
        }

        if (isNeedingMoreRoom)
        {
            vector<pair<int, int>> newRoom{ make_pair(currentStartTime, currentEndTime) };
            rooms.push_back(newRoom);
        }
    }

    return rooms.size();
}