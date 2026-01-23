#include <iostream>
using namespace std;

class student
{
public:
    int roll;
    void display();
};   // semicolon was missing

void student::display()
{
    cout << "Roll number: " << roll << endl;
}

int main()
{
    student s1;
    s1.roll = 10;
    s1.display();
    return 0;
}

