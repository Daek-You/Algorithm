#include <iostream>
#include <set>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int answer = 0;
	set<string> chattingRoom;
	for (int i = 0; i < N; i++)
	{
		string message;
		cin >> message;

		if (message == "ENTER")
		{
			chattingRoom.clear();
			continue;
		}

		auto personIt = chattingRoom.find(message);
		if (personIt == chattingRoom.end())
		{
			chattingRoom.insert(message);
			answer++;
		}
	}

	cout << answer;
	return 0;
}