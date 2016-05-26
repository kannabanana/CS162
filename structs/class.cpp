#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class student
{
public:
	int number;	
	student(char parName[],int size);
	~student();
private:
	char * pname;
	char SSN[10];

student(char parName[],int size)
{
	pname = new char[size];
	strcpy(name,parName);
        SSN[0] = '\0';	

}

;


//void name(student identity[],int & i);



int main ()
{
int i = 0;
int size = 20;
char array[200];
cout << "Enter: ";
cin.get(array,200,'\n'); cin.ignore(100,'\n');
student identity(array,strlen(array)+1);

identity.number = 1000;
cout << identity.number << endl;

/*do{
name(identity,i);
++i;
}
while(i<2);

for (int k = 0; k < 2; ++k)
	cout << identity[k].number << endl;
return 0;
}

void name(student identity[], int & i)
{

cout << "Number: ";
cin >> identity[i].number;
cin.ignore(100,'\n');
}
*/
return 0;

}


