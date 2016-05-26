#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
char name[22];
int count = 0;

cout << "Enter you name: ";
cin.get(name,22,'\n');
cin.ignore(100,'\n');

int len = strlen(name);
for (int i = 0; i < len; ++i)
{
	if (name[i] >= 'a' && name[i] <= 'z')
	{
		++count;	
	}
}
	cout << count << endl;

return 0;
}
