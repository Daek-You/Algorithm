#include <string>
#include <vector>
#include <set>
using namespace std;

class File {
public:
    File(int id, const string& fileName) {
        _id = id;
        _originalName = fileName;
        Init();
    }

    string ToLower(const string& str) {
        string result(str);
        for (int i = 0; i < result.length(); i++)
            result[i] = tolower(result[i]);
        return result;
    }

    bool operator<(const File& other) const {
        int dictionaryOrder = _head.compare(other._head);


        if (dictionaryOrder == 0) {
            if (_number.empty() or other._number.empty())
                return _id < other._id;

            int myNum = stoi(_number);
            int otherNum = stoi(other._number);
            return myNum != otherNum ? myNum < otherNum : _id < other._id;
        }
            
        return dictionaryOrder < 0;
    }

private:
    void Init() {
        int begin = 0, i = 0, end = _originalName.length();

        /* HEAD 처리 */
        for (; i < end; i++) {
            if (isdigit(_originalName[i])) {
                _head = ToLower(_originalName.substr(begin, i));
                begin = i;
                break;
            }
        }

        if (i == end) {
            _head = ToLower(_originalName.substr(begin, i));
            return;
        }


        /* NUMBER 처리 */
        for (; i < end; i++) {
            if (!isdigit(_originalName[i])) {
                _number = _originalName.substr(begin, i - begin);
                begin = i;
                break;
            }
        }

        if (i == end) {
            _number = _originalName.substr(begin, i - begin);
            return;
        }

        /* TAIL 처리 */
        _tail = _originalName.substr(begin);
    }

public:
    int _id;
    string _originalName;
    string _head;
    string _number;
    string _tail;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    set<File> orderedFiles;

    for (int i = 0; i < files.size(); i++)
        orderedFiles.emplace(File(i, files[i]));

    for (const auto file : orderedFiles)
        answer.emplace_back(file._originalName);
    return answer;
}