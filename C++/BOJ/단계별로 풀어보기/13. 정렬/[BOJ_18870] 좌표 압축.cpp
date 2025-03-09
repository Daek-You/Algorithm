#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> originalPositions(N);
	vector<int> distinctSortPositions(N);
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		originalPositions[i] = data;
		distinctSortPositions[i] = data;
	}

	sort(distinctSortPositions.begin(), distinctSortPositions.end());
	/*
		unique(x, y) 함수는 x부터 y까지 중복된 값이 나온 값 하나를 빼고, 나머지는 전부 맨 뒤에 보낸 후, 그 인덱스 첫 시작점을 리턴
		unique(x, y) 함수는 정렬이 되어 있어야, 정확하게 중복된 값 제거가 가능
		erase(x, y) 함수는 x부터 y까지를 제거
	*/

	/* 중복된 값 제거 */
	distinctSortPositions.erase(unique(distinctSortPositions.begin(), distinctSortPositions.end()), distinctSortPositions.end());
	
	/*
		lower_bound(시작값, 종료값, 찾는 값) 함수는 이진 탐색을 통해, 찾는 값보다 같거나 큰 값을 리턴해준다.
		리턴값이 iterator이므로, begin()을 빼주면 인덱스를 구할 수 있다.
	*/
	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(distinctSortPositions.begin(), distinctSortPositions.end(), originalPositions[i]) - distinctSortPositions.begin() << " ";
	}
	return 0;
}