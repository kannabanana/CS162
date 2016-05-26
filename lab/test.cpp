#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main ()
{

char response;
cout << "Enter: " << endl;
cin >> response;
cin.ignore(100,'\n');

if (response < 'a')
{
	cout << "Lowercase" << endl;
}
else
{
	cout << "Correct!" << endl;
}
return 0;
}
