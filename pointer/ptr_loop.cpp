#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
//display all
char phrase[200];
cout << "Enter: ";
cin.get(phrase,200,'\n'); cin.ignore(100,'\n');

char * ptr = phrase;	//assigns ptr to the starting location of phrase -gives it the address
int len = strlen(ptr);		//DON'T KNOW WHAT THIS DOES

//use a counter and count the number of lower cases
int count = 0;
for (int i = 0; i < len; ++i)
{
	if (*ptr >= 'a' && *ptr <= 'z' || *ptr >= 'A' && *ptr <= 'Z')
		++count;
	++ptr;
}
cout << "The number of lowercase is: " << count << endl;
return 0;
}
