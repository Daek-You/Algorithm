#include <iostream>
using namespace std;

class MyGrades {
	int* p;
	int size, Max;
public:
	MyGrades(int size) { p = new int[size]; this->size = size; }
	~MyGrades() { delete[]p; }
	void setMyGrades() { for (int i = 0; i < size; i++) cin >> p[i];}
	void setMaxGrade();
	double getNewGradeSum();
};

void MyGrades::setMaxGrade() {
	int max = p[0];

	for (int i = 1; i < size; i++)
		if (max < p[i])
			max = p[i];
	this->Max = max;
}

double MyGrades::getNewGradeSum() {
	double sum = 0.0;

	for (int i = 0; i < size; i++) 
			sum += ((double)p[i] / Max) * 100;
	
	return sum;
}


int main() {
	
	int n;

	cin >> n;
	MyGrades mg(n);
	mg.setMyGrades();
	mg.setMaxGrade();
	double newAvg = mg.getNewGradeSum();

	cout << newAvg / n;

	return 0;
}