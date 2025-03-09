#include <iostream>
#include <deque>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int documentNum, targetDocumentIndex;
		cin >> documentNum >> targetDocumentIndex;

		deque<pair<int, bool>> documentImportances;
		for (int i = 0; i < documentNum; i++)
		{
			int importance;
			cin >> importance;
			documentImportances.push_back(make_pair(importance, i == targetDocumentIndex));
		}

		int answer = 0;
		while (!documentImportances.empty())
		{
			auto document = documentImportances.front();
			bool isAvailablePrint = true;

			for (int i = 1; i < documentImportances.size(); i++)
			{
				if (document.first < documentImportances[i].first)
				{
					documentImportances.push_back(document);
					documentImportances.pop_front();
					isAvailablePrint = false;
					break;
				}
			}

			if (isAvailablePrint)
			{
				answer++;
				documentImportances.pop_front();
				if (document.second)  // 우리가 찾던 문서라면 중지
					break;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}