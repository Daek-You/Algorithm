#include <iostream>
using namespace std;

int main()
{
    unsigned int students = 0;
    unsigned int submittedStudentID;

    for (int i = 0; i <= 28; i++)
    {
        cin >> submittedStudentID;
        students = students | (1 << submittedStudentID - 1);
    }

    for (int i = 0; i < 30; i++)
    {
        if (!(students & (1 << i)))
        {
            cout << i + 1 << endl;
        }
    }
    
    return 0;
}