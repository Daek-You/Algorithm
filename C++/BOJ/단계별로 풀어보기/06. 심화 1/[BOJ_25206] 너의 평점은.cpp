#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, float> gradeTable
	{
		{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0},
		{"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0},
		{"P", 0.0},  {"F", 0.0}
	};
	
	float calculatedGrade = 0;
	float totalGradeSum = 0;

	for (int i = 0; i < 20; i++)
	{
		string input;
		getline(cin, input);

		string buffer;
		stringstream tokenizer(input);
		int tokenCount = 0;
		float grade = 0;

		while (tokenizer >> buffer)
		{
			switch (tokenCount)
			{
			case 1:
				grade = stof(buffer);
				break;

			case 2:
				if (buffer != "P")
				{
					totalGradeSum += grade;
					calculatedGrade += grade * gradeTable[buffer];
				}

				else if (buffer == "F")
				{
					totalGradeSum += grade;
				}

				break;
			}

			tokenCount++;
		}
	}

	cout << calculatedGrade / totalGradeSum;
	return 0;
}