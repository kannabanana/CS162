#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

/*
SR Kanna
Program 3
CS 162
2.17.2014

DESCRIPTION:

This program will take course information from the user for four years to help them plan their plan of action. Each class will include the course (Department and section), name, if it's required, grade, the term, year and any additional comments the uer wishes to add. The user can store up to 60 classes in memory.

ALGORITHM:
I. Four Year Course Plan

	A. Read in
		i. Read information from the external file to see how many previous classes have been stored by the user
		ii. parametere for the function is the structure and i (pass by reference)
		iii. check to see if the file is open
		iv. if the file is open
			a. have a while loop 
				i. condition is that as long information exists and i is less than 60
				ii. read in information into structre using file_in.get
				iii. use file_in.ignore
				iv. make sure to use '\n'
			b. increment i by one
		v. decrease value of i by one for user data
		vi. close file
	B. User Data
		i. get information from user in main through do while
			a. repeats as long as user wants to and i is less than 60
		ii. pass stucture and int i by reference
		iii. prompt user for information and store in structure
		iv. store information using cin.get
			a. object.member
			c. cin.ignore
		v. make sure to make member (plan) array of 60
	C. Write Out
		i. write out function is called once all information is written by the user
		ii. pass structure and i by value to function
		iii. open file and check to see if it's open and go through if statements 
		iv. use for loop to loop through
			a. initialize j to zero, i is limit, and increment j by one
			b. write out to external file
		v. close file
	D. Display
		i. display everything
			a. cout all strucutre terms
			b. use tabs as spacs
		ii. display by term
			a. using strmcmp
				a. get user information
				b. make sure it's equivilent and cout all information under that term
				c. use tabs as spaces
*/				

using namespace std;

//STRUCT:

struct course_plan							//array of structures to hold class information
{

char course[20];							//array to hold course
char name[100];								//array for name
char required[20];							//array if the course is required
char grade[20];								//array for grade
char term[20];								//array for which term
char year[20];								//array for the year
char comment[200];							//array for comments

};

//PROTOTYPES:

void fourplan(course_plan * plan, int & i);				//Prototype to get class information from user
void write_out(course_plan * plan,int i);				//Prototype to write to the external file
void read_in(course_plan[], int & i);					//Prototype to read from the external file
void display(course_plan * plan, int i);				//Prototype to display all information
void display2(course_plan * plan, int i);				//Prototype to display information by term

int main ()
{

//VARIABLES:

int i = 0;								//i counts the number of classes
char response;								//user response
course_plan plan[60]; 							//object

read_in(plan,i);							//calling function to read from external file

do
{
cout << "Welcome to the course plan. Please enter what classes you will take for the next four years. This program can support up to 60 classes. " << endl << endl;
cout << "Please enter information for class number " << i+1 << ". " << endl << endl;

	fourplan(plan,i);								//Calling function to enter data
	++i;										//increment class number

	cout << "Do you want to continue? Y/N. ";					//User decision to continue
	cin >> response;
	cin.ignore(100,'\n');
}

while ('Y' == toupper(response) && i <= 60);						//condition to do over (less than 60 classes and user wnats to)
write_out(plan,i); 									//calling function to write out user information

cout << "Do you want to see all classes under a term? Y/N. N will display all information. ";		//figuring out how the user wants to display information
cin >> response;
cin.ignore(100,'\n');
if ('Y' == toupper(response))
	display2(plan,i);								//calling function to display information by term
else
	display(plan,i);								//calling function to display everything 

return 0;
}



//FUNCTIONS:

//Function reads in information from the user for each class

void fourplan(course_plan * plan, int & i)
{

cout << "What term? Example: Winter. " << endl;							//adds to member term
cin.get(plan[i].term,20,'\n');
cin.ignore(100,'\n');

cout << "What year is this class in? " << endl;							//adds to member year
cin.get(plan[i].year,20,'\n');
cin.ignore(100,'\n');

cout << "What department and class number is this class in? Example: CS162. " << endl;		//adds to member course
cin.get(plan[i].course,100,'\n');
cin.ignore(100,'\n');

cout << "What is the name of the course? Example: Introduction to Computer Science. " << endl;	//adds to member name
cin.get(plan[i].name,100,'\n');
cin.ignore(100,'\n');

cout << "Is this class required? Y/N. " << endl;
cin.get(plan[i].required,20,'\n');								//adds to member required
cin.ignore(100,'\n');

cout << "Please add any additional comments to this course. Limit to 200 characters. " << endl;	//adds to member comment
cin.get(plan[i].comment,200,'\n');
cin.ignore(100,'\n');

cout << "You may enter your grade for this class. A-F or NA if Not Applicable. " << endl;	//adds to member grade
cin.get(plan[i].grade,20,'\n');
cin.ignore(100,'\n');

}

//This function writes to the external file

void write_out(course_plan * plan,int i)
{
	ofstream file_out;
	file_out.open("hw3_ex.txt");								//opens file
	if (file_out)										//checks if it's open
	 {	
		for (int j = 0; j < i; ++j)
		{
			file_out << plan[j].term <<'\n'  					//writes to the file
				<< plan[j].year <<'\n'
				<< plan[j].course <<'\n'
				<< plan[j].name <<'\n'
				<< plan[j].required <<'\n'
				<< plan[j].comment <<'\n'
				<< plan[j].grade<<endl;
		}
		file_out.close();								//closes file
 	}	
}

//This function reads from the external file and writes to the structures

void read_in(course_plan plan[], int & x)
{
	ifstream file_in;
	file_in.open("hw3_ex.txt");								//opens file								
        if (!file_in)										//check if it's not open
		return;
	else						
	{
		
			while(!file_in.eof() && x < 60)						//as long content and less than 60 classes
			{
				file_in.get(plan[x].term,20,'\n');				//reads into structure
				file_in.ignore(100,'\n');					//ignore ('\n')
				
				file_in.get(plan[x].year,20,'\n');
				file_in.ignore(100,'\n');
			
				file_in.get(plan[x].course,100,'\n');
				file_in.ignore(100,'\n');
	
				file_in.get(plan[x].name,100,'\n');
				file_in.ignore(100,'\n');

				file_in.get(plan[x].required,20,'\n');
				file_in.ignore(100,'\n');

				file_in.get(plan[x].comment,200,'\n');
				file_in.ignore(100,'\n');

				file_in.get(plan[x].grade,20,'\n');
				file_in.ignore(100,'\n');
				++x;								//increment i
                                
			}
		--x;										//decrement i, so that in int main class appears correct number
		file_in.close();								//close file
	}
}

//This function displays all classes

void display (course_plan * plan, int i)
{
for (int k = 0; k < i; ++k)									//display everything as long it's less than number of classes
{
	cout 	<< plan[k].term << '\t'
		<< plan[k].year << '\t'
		<< plan[k].course << '\t'
		<< plan[k].name	<< '\t'
		<< plan[k].required << '\t'
		<< plan[k].comment << '\t'
		<< plan[k].grade << endl;
}
}

//This function displays only specific classes based on the term user enters

void display2 (course_plan * plan, int i)
{
char term[10];											//get info from user
	cout << "Please enter the term you want to see: ";
	cin.get(term,10,'\n');
	cin.ignore(100,'\n'); 

for (int k = 0; k < i; ++k)
{
	if(strcmp(plan[k].term,term) == 0)							//strcmp with user
		cout << plan[k].course << '\t';							//if it's the same, then all classes will displayed that match
}		
}



