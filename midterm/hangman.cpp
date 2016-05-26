#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
char phrase[100];
char answer[100];

for (int i = 0; i <=100; ++i)
{
	phrase[i] = '\0';
}

	cout << "Enter a phrase less than a 100 characters: " << endl;
	cin.get(phrase,100,'\n');
	cin.ignore(100,'\n');

int len = strlen(phrase);
for (int i = 0; i < len; ++i)
{
	if (phrase[i] == ' ')
	{
		answer[i]= ' ';
	}
	else
	{
		answer[i] = '_';
	}
}

cout << answer << endl;



return 0;
}
