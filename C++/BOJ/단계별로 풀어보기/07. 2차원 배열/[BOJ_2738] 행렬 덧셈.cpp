#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>& CreateMatrix(int row, int column)
{
	vector<vector<int>>* matrix = new vector<vector<int>>();

	for (int i = 0; i < row; i++)
	{
		vector<int> rowData;

		for (int j = 0; j < column; j++)
		{
			int data;
			cin >> data;
			rowData.push_back(data);
		}

		matrix->push_back(rowData);
	}

	return *matrix;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>>& matrix1 = CreateMatrix(N, M);
	vector<vector<int>>& matrix2 = CreateMatrix(N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix1[i][j] + matrix2[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}