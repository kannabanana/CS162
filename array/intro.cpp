#include <iostream>
#include <cstring>
#include <cctype>
including namespace std;
//SR Kanna, CS 162
//using this program to introduce arrays. Output, input etc
//get 5 program scores and display average
const int NAME_SIZE=21;  //constants are always in capitals
const int GRADE_SIZE=5;
int main()
{
//define variables
	char name[NAME_SIZE];
	float grades[GRADE_SIZE];
	int num_of_grades=0;
	char response='n';
	float sum=0.0;

	cout<<"Please your full name ";
	cin.get(name, NAME_SIZE,'\n');    //this is how to incoprorate Input into the array
	cin.ignore(100,'\n');
	
	cout<<name<<" how many grades do you have?";
	cin>>num_of_grades;
	cin.ignore(100,'\n'); //ignores 100 char
	
	cout<<"Please enter "<<num_of_grades<<" scores: ";
	if (num_of_grades>GRADES_SIZE)
		num_of_grades=GRADE_SIZE;
	//read in all of their grades
	for(int i=0; i<num_of_grades;++i)
	{ 
		cin>>grades[i];
		sum+=grades[i];
	}
	float average =sum/num_of_grades;

	//display our results
	cout<<name<<"'s grades are: ";
	for (int i=0;i<num_of_grades;++i)
	{
		cout<<grades[i]<<' ';
	}
	cout<<"/nAveraging: "<<average<<endl;

return 0;
}
