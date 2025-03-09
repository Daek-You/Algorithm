#include <iostream>
using namespace std;

void Reverse(int* array, int rbegin, int rend)
{
	if (rbegin == rend)
		return;

	for (int i = rbegin - 1; i < rend; i++)
	{
		int temp = array[i];
		array[i] = array[rend - 1];
		array[rend - 1] = temp;
		rend--;
	}
}

void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

int main() {
	int N, M;
	cin >> N >> M;
	
	int* array = new int[N] { 0 };
	for (int i = 0; i < N; i++)
		array[i] = i + 1;

	for (int i = 0; i < M; i++)
	{
		int rbegin, rend;
		cin >> rbegin >> rend;
		Reverse(array, rbegin, rend);
	}

	Print(array, N);
	return 0;
}

