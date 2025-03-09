#include <iostream>
#include <deque>
using namespace std;

template<typename T>
class RotationQueue
{
public:
	RotationQueue(int n)
	{
		for (int i = 1; i <= n; i++)
			_data.push_back(i);
	}
	void Push_back(const T& data) { _data.push_back(data); }
	void Pop_front() 
	{
		_data.pop_front();
	}


	void PerformOptimalOperation(int position)
	{
		position = FindDataIndex(position);

		if (position == -1)
			return;

		// 앞에서 뽑는 게 이득인지, 뒤의 데이터를 앞으로 이동하여 뽑는 게 이득인지
		bool turnLeft = position <= (_data.size() - position);
		int operationNums = turnLeft ? (position) : (_data.size() - position);

		for (int i = 0; i < operationNums; i++)
		{
			turnLeft ? RotateLeft() : RotateRight();
		}

		Pop_front();
	}

	int OperationCount() { return _operationCount; }
private:
	int FindDataIndex(int data)
	{
		int index = -1;
		for (int i = 0; i < _data.size(); i++)
		{
			if (_data[i] == data)
			{
				index = i;
				break;
			}
		}
		return index;
	}


	void RotateLeft()
	{
		auto data = _data.front();
		_data.pop_front();
		_data.push_back(data);
		_operationCount++;
	}

	void RotateRight()
	{
		auto data = _data.back();
		_data.pop_back();
		_data.push_front(data);
		_operationCount++;
	}

private:
	deque<T> _data;
	int _operationCount = 0;
};

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	RotationQueue<int> queue(n);
	for (int i = 0; i < m; i++)
	{
		int position;
		cin >> position;
		queue.PerformOptimalOperation(position);
	}

	cout << queue.OperationCount();
	return 0;
}