#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

class name			//basic struct
{
public:
	int age;
	int size;
	int weight;
	char add[200];
};

void func(name [], int &i);

int main()
{
name identity[10];
int i = 0;

func(identity,i);

return 0;
}

void func(name * identity, int &i)
{
cout << "Enter age: ";
cin >> identity[i].age; cin.ignore(100,'\n');
cout << identity[i].age << endl;
}
