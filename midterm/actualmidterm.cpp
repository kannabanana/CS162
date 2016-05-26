#include <isotream>
#include <cctype>
#include <cstring>
using namespace std;
bool find(char user[]);
int main()
{
char user[20];
cout << "Enter: ";
cin >> user;
cin.ignore(100,'\n');

find(user);

return 0;
}

bool find(char user[])
{
char actual[3] = {'h','i'};
int len = strlen(user);
for (int i = 0; i <len;++i)
{
	if (actual[i] == 'h')
	{	if(actual[i+1] == 'i')
			return true;
	}
}
	else
		return false;
}
