#include <iostream>
#include <cctype>
#include <cstring>

void read_name(char name[]);
void read_course(char CRN[],char course[],int & section);
bool again ();
using namespace std;

int main()
{
char name[21];
char CRN[10];
char course[10];
int section;
do
{read_name(name);
read_course(CRN,course,section);
} while (again());
return 0;
}

void read_name(char name[])
{
cout << "Enter you name: ";
cin.get(name,21,'\n');
cin.ignore(100,'\n');
cout << name << endl;
}

void read_course(char CRN[],char course[],int & section)
{
cout << "Enter CRN: ";
cin.get(CRN,10,'\n');
cin.ignore(100,'\n');

cout << "Enter course ";
cin.get(course,10,'\n');
cin.ignore(100,'\n');

cout << "Enter section: ";
cin >> section;
cin.ignore(100,'\n');

cout << "CRN " << CRN << endl;
cout << "Course " << course << endl;
cout << "Section " << section << endl;

}

bool again()
{
char response;
cout << "Do you want to continue? ";
cin >> response;
if ('Y' == toupper(response))
	return true;
}
