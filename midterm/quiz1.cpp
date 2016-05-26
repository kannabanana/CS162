#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main ()
{

int num1,num2;

cout << "Enter numbers: ";
cin >> num1 >> num2;
cin.ignore(100,'\n');

cout << num1 << num2;
return 0;
}
