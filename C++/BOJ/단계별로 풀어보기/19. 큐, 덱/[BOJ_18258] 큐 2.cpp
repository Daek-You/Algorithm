#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> _queue;
	for (int i = 0; i < N; i++)
	{
		string instruction;
		cin >> instruction;

		if (!instruction.compare("push"))
		{
			int data;
			cin >> data;
			_queue.push(data);
		}

		else if (!instruction.compare("pop"))
		{
			if (_queue.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << _queue.front() << '\n';
			_queue.pop();
		}

		else if (!instruction.compare("size"))
		{
			cout << _queue.size() << '\n';
		}

		else if (!instruction.compare("empty"))
		{
			cout << _queue.empty() << '\n';
		}

		else if (!instruction.compare("front"))
		{
			if (_queue.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << _queue.front() << '\n';
		}

		else if (!instruction.compare("back"))
		{
			if (_queue.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << _queue.back() << '\n';
		}
	}

	return 0;
}