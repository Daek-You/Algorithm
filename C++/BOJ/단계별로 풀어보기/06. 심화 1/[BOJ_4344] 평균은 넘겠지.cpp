#include <iostream>
#include <vector>
using namespace std;

void Print(float result)
{
	// 소수점 3자리로 고정
	cout << fixed;
	cout.precision(3);
	cout << result << "%" << endl;
}

float GetAverage(const vector<int>& grades)
{
	int sum = 0;
	
	for (auto grade : grades)
		sum += grade;

	return static_cast<float>(sum / grades.size());
}

int main()
{
	int testCaseNums;
	cin >> testCaseNums;

	for (int i = 0; i < testCaseNums; i++)
	{
		int studentNums;
		cin >> studentNums;

		vector<int> grades;
		for (int j = 0; j < studentNums; j++)
		{
			int grade;
			cin >> grade;
			grades.push_back(grade);
		}

		float average = GetAverage(grades);
		int averageOverStudentNums = 0;

		for (int j = 0; j < studentNums; j++)
		{
			if (static_cast<float>(grades[j]) > average)
				averageOverStudentNums++;
		}
		
		Print(100 * (static_cast<float>(averageOverStudentNums) / studentNums));
	}
	return 0;
}