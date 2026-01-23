#include<iostream>
#include<string>
using namespace std;
class student
{
	public:
	string name;
	int rollno;
		int semister;
		char section;
		
		void setData(string n, int s, int r, char sec)
		{
name=n;
 rollno = r;
semister = s;
section = sec;
			
		}
void desplay()
{
	cout << "name: " << name << endl;
cout << "rollno: "	<< rollno << endl;
cout << "semister: " << semister << endl;
cout << "section: " << section << endl << endl;
		}		
};

int main()
{
student s[4];
    s[0].setData("Ali", 1, 3, 'A');
    s[1].setData("Ahmed", 2, 3, 'B');
    s[2].setData("Sara", 3, 2, 'A');
    s[3].setData("Ayesha", 4, 1, 'C');

    cout << "Students from Section A:\n\n";
    for (int i = 0; i < 4; i++) {
        if (s[i].section == 'A') {
            s[i].	desplay();
        }
    }
    return 0;
}
	

