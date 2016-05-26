#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main()
{
char letter = 'a';
char * ptr = &letter;			//need &

cout << "The location of ptr is: " << &ptr << endl;
cout << "The place where ptr is pointing to is: " << ptr << endl;
cout << "Ptr has this in memory: " << *ptr << endl;

int num = 1;
int * count = &num;			//need &

cout << "Location of count: " << &count << endl;
cout << "Place where count is poitning: " << count << endl;
cout << "What count has in memory: " << *count << endl;

return 0;
}
