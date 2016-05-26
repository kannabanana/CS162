#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main ()
{
char initial[4];
float wages = 0.0;
int hours;
char response;

do
{

cout << "Enter you initials: " << endl;
cin >> initial;
cin.ignore(100,'\n');

for (int i = 0; i < 4; ++i)
{
	initial[i] = toupper(initial[i]);
}
	cout << initial << endl;


cout << "Please enter you hourly wages: ";
cin >> wages;
cin.ignore(100,'\n');

while (wages < 0)
{	
cout << "Sorry. That was an invalid entry. Please enter you hourly wages: ";
cin >> wages;
cin.ignore(100,'\n');
}

cout << "You entered: " << wages << endl;

cout << "Please enter the number of hours you work: ";
cin >> hours;
cin.ignore(100,'\n');

while (hours < 0)
{
cout << "Sorry. Invalid entry. Try again. ";
cin >> hours;
cin.ignore(100,'\n');
}

cout << "You entered: " << hours << endl;

float total = hours*wages;
cout << total << endl;

cout << "Will there be a cost of living increase? ";
cin >> response;
cin.ignore(100,'\n');

response = toupper(response);
if ('Y' == response)
{
	cout << "How much increase? ";
	cin >> increase;
	cin.ignore(100,'\n');
	while (increase < 0)
	{
	cout << "You entered an invalid value. ";
	cin >> increase;
	cin.ignore(100,'\n');
	while (increase < 'z' )
	{
		cout
	}
	cout << increase*.15 << endl;
}
}

while ('Y' == response)
return 0;
}
