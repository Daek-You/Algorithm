#include <iostream>
#include <vector>
using namespace std;
using Position = pair<int, int>;

class City
{
public:
	City(int N, int M);

	int GetMinChickenStreet();

private:
	int GetDistance(const Position& p1, const Position& p2) { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }
	void GetMinChickenStreet(vector<int>& selectedChickens, int currentIdx);

private:
	const int HOUSE = 1;
	const int CHICKEN = 2;
	const int INIT_VALUE = 1000000000;

	vector<Position> _houses;
	vector<Position> _chickens;

	int _minChickenStreet = INIT_VALUE;
	int _M;
};

City::City(int N, int M)
{
	_M = M;

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			int information;
			cin >> information;

			if (information == HOUSE)
				_houses.emplace_back(row, col);
			else if (information == CHICKEN)
				_chickens.emplace_back(row, col);
		}
	}
}

void City::GetMinChickenStreet(vector<int>& selectedChickens, int currentIdx)
{
	if (selectedChickens.size() == _M)
	{
		int sum = 0;
		for (int hi = 0; hi < _houses.size(); hi++)
		{
			int minDistance = INIT_VALUE;
			for (const int& ci : selectedChickens)
				minDistance = min(minDistance, GetDistance(_houses[hi], _chickens[ci]));
			
			sum += minDistance;
			if (sum > _minChickenStreet)
				return;
		}

		_minChickenStreet = min(_minChickenStreet, sum);
		return;
	}

	for (int i = currentIdx; i < _chickens.size(); i++)
	{
		selectedChickens.emplace_back(i);
		GetMinChickenStreet(selectedChickens, i + 1);
		selectedChickens.pop_back();
	}
}

int City::GetMinChickenStreet()
{
	vector<int> selectedChickens;
	GetMinChickenStreet(selectedChickens, 0);
	return _minChickenStreet;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	City city(N, M);
	cout << city.GetMinChickenStreet();
	return 0;
}