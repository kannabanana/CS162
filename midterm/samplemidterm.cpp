#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main ()
{
char array1[100];
char array2[6] = {'c','a','t'};
cout << "Enter a word: ";
cin >> array1;
cin.ignore(100,'\n');

if (strcmp(array1,array2)> 0)
	cout << "bigger" << endl;
else
	cout << "smaller" << endl;


return 0;

}
