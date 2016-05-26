#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main ()
{
char name[100];
char interest[10];
char response;

do
{
	cout << "Enter a name: ";
	cin.get(name,100,'\n');
	cin.ignore(100,'\n');

	name[0] = toupper(name[0]);
	int len = strlen(name);
	for (int i =0; i < len; ++i)
{ 		
		if (name[i] == ' ')
	{
			name[i+1] = toupper(name[i+1]);
	}	
}
	cout << name << endl;

	cout << "Interest: ";
	cin.get(interest,10,'\n');
	cin.ignore(100,'\n');

	int len1 = strlen(interest);

	while (len1 > 10)
	{
		cout << "You entered too many characters. ";
		cin.get(interest,10,'\n');
		cin.ignore(100,'\n');
	}

	cout << "Do you want to continue? ";
	cin >> response;
	cin.ignore(100,'\n');
}

while ('Y' == toupper(response));
return 0;
}
