#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Data
{
public:
    void Insert(int id, int playTime)
    {
        _songs.emplace(Song(id, playTime));
        _totalPlayTime += playTime;
    }

    vector<int> GetBestSongs()
    {
        auto start = _songs.begin();

        if (_songs.size() >= 2)
            return { _songs.begin()->_id, (++start)->_id };
        return { _songs.begin()->_id };
    }

    int GetTotalPlayTime() const { return _totalPlayTime; }
private:
    struct Song
    {
        Song() { }
        Song(int id, int playTime) : _id(id), _playTime(playTime) { }

        bool operator<(const Song& other) const
        {
            if (_playTime == other._playTime)
                return _id < other._id;
            return _playTime > other._playTime;
        }
        int _id;
        int _playTime;
    };

private:
    set<Song> _songs;
    int _totalPlayTime = 0;
};

bool Compare(const pair<string, Data>& a, const pair<string, Data>& b)
{
    return a.second.GetTotalPlayTime() > b.second.GetTotalPlayTime();
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, Data> streamings;
    int N = genres.size();

    for (int i = 0; i < N; i++)
        streamings[genres[i]].Insert(i, plays[i]);

    vector<pair<string, Data>> candidates(streamings.begin(), streamings.end());
    sort(candidates.begin(), candidates.end(), Compare);

    vector<int> answer;
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> bestSongs = candidates[i].second.GetBestSongs();

        for (const auto& songID : bestSongs)
            answer.push_back(songID);
    }

    return answer;
}