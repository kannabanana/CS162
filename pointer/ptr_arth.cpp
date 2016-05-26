#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
///////Int arrays:
/*int num[10] = {1,2,3,4,5,6,7,8,9};
int *ptr = num;		//optional &

ptr = &num[5];		//mandatory &
* ptr = 6;
cout << "The value of ptr without using * is: " << *ptr << endl;


cout << "The value ptr is storing in memory is: " << *ptr << endl;
cout << "The location ptr is pointing to is: " << ptr << endl;		//this is correct
cout << "The location of ptr is: " << ptr << endl;
*/

///////This is w/char arrays:

char array[200];
char *temp = array;	//no &

cout << "Enter your phrase: ";
cin.get(array,200,'\n'); cin.ignore(100,'\n');

int len = strlen(temp);
cout << *(temp +strlen(temp)-1);
//*temp = toupper (*temp+len-1);
//cout << *temp << endl;

return 0;
}
