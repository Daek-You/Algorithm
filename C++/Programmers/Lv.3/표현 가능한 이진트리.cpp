#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define DUMMY 			'0'
#define REAL_NODE 		'1'
#define VISITED_NODE	'2'

string ConvertToBinary(long long number)
{
	string binary = "";

	while (number)
	{
		binary += to_string(number % 2);
		number /= 2;
	}

	reverse(binary.begin(), binary.end());
	return binary;
}

void MakeFullBinaryTree(string& binary)
{
	long long numOfNodes = binary.length();
	long long height = 1;

	while (true)
	{
		long long currentNumOfNodes = static_cast<long long>(pow(2, height)) - 1;
		
		if (currentNumOfNodes >= numOfNodes)
		{
			long long difference = currentNumOfNodes - numOfNodes;
			string dummies(difference, DUMMY);
			binary.insert(0, dummies);
			break;
		}

		height++;
	}
}

bool IsAvailable(const string& tree, long long left, long long right)
{
	if (left == right)
		return true;
	
	long long mid = (left + right) / 2;

	if (tree[mid] == DUMMY)
	{
		for (long long i = left; i <= right; i++)
			if (tree[i] == REAL_NODE)
				return false;
		return true;
	}

	return IsAvailable(tree, left, mid - 1) and IsAvailable(tree, mid + 1, right);
}

vector<int> solution(vector<long long> numbers)
{
	int N = numbers.size();
	vector<int> answers(N);

	for (int i = 0; i < N; i++)
	{
		string binary = ConvertToBinary(numbers[i]);
		MakeFullBinaryTree(binary);
		answers[i] = IsAvailable(binary, 0, binary.length() - 1);
	}

	return answers;
}