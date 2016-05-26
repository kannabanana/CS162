#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
char name[9];
int age;
cout << "What's your name? ";
cin.get(name,9,'\n');
cin.ignore(100,'\n');

cout << "How old are you? ";
cin >> age;
cin.ignore(100,'\n');

cout << name << " " << age << endl;
return 0;
}
