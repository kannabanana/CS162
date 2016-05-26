#include <iostream>
#include <cctype>
using namespace std;
int main()
{
char response='y';
float cost=0.0;
 do
{
 cout<<"What is the cost? $";
 cin>>cost;
 cout<<"You entered: "<<cost;
 cout<<"Is this correct? ";
 cin>>response;
 response=tolower(response);

 if ('y'==response)
 {  char grade='A';
    float tip=0.0;

    cout<<"Let's get started!"<<endl;
    cout<<"Rate the service you recieved.( A,B,C,F) ";
    cin>>grade;
    grade=toupper(grade);
    switch(grade)
	{
	case 'A':
		tip=cost*.15;
		cout<<cost;
		break;
	case 'B':
		tip=cost*.1;
		cout<<cost;
		break;
	case 'C':
		tip=cost*.05;
		cout<<cost;
		break;
	default:
		tip=0.0;
		cout<<tip;
		break;
	}
 }
}
 while('y'!=response);
 return 0;
}
