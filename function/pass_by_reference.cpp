#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int print(int num,int & num2,int * ptr);

int main()
{

int num = 10;
int num2 = 15;
int * ptr = NULL;
int num3 = 10;
ptr = &num3;			//this integer pointer, ptr, is assigned to the address of the integer variable, num3

print(num,num2,ptr);

cout << "Num3 pointer changed value is: " << *ptr << endl;
//ptr = ptr+!

return 0;
}

int print(int vNum,int & rNum2, int * ptr)
{
cout << "value: " << vNum << endl;
cout << "referenced value is: " << rNum2 << endl;	

//changing the value of num3 through ptr:
* ptr = 15;

}
