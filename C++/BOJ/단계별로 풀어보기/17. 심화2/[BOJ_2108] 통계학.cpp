#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;

bool compare(const std::pair<int, int>& sample1, const std::pair<int, int>& sample2)
{
	if (sample1.second == sample2.second)
		return sample1.first < sample2.first;
	return sample1.second > sample2.second;
}


int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	std::vector<int> sampleVector(N);
	std::map<int, int> sampleMap;
	double sum = 0;
	bool isDuplicated = false;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;

		sum += data;
		sampleVector[i] = data;
		auto findIt = sampleMap.find(data);
		
		if (findIt == sampleMap.end())
		{
			sampleMap.insert(std::make_pair(data, 1));
			continue;
		}

		sampleMap[data]++;
		if (!isDuplicated)
			isDuplicated = true;
	}
	
	cout << static_cast<int>(round(sum / N)) << '\n';   // 산술평균
	
	std::sort(sampleVector.begin(), sampleVector.end());
	int targetIdx = (N / 2) + 1;

	for (int i = 0; i < targetIdx; i++)
	{
		if (i == N / 2)
		{
			cout << sampleVector[i] << '\n';            // 중위수
			break;
		}
	}

	
	std::vector<std::pair<int, int>> arr(sampleMap.begin(), sampleMap.end());
	std::sort(arr.begin(), arr.end(), compare);

	if ((arr.size() > 1) && ((isDuplicated && arr[0].second == arr[1].second) || !isDuplicated))
			cout << arr[1].first << '\n';
	else
		cout << arr[0].first << '\n';

	cout << sampleVector[N - 1] - sampleVector[0];    // 범위
	return 0;
}