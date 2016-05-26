//.h file
//#include, const, structures, prototypes, class, interface

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct video
{
	char * title;			//dynamically allocated array
	char * description;		
};

//linear linked list

struct node
{
	video movie;
	node * next;
};

int main ()
{

	char response;
	node * head = NULL;		//empty list
	node * temp;
	node * current;			//helper
	char title[100], description[100];	//temporary arrays to store
do{
	cout << "Please enter a movie's info: ";
	cin.get(title,100,'\n');
	cin.ignore(100,'\n');
	cin.get(description,100,'\n');
	cin.ignore(100,'\n');

	//store into the list
	temp = new node;
	temp->movie.title = new char [strlen(title)+1];
	strcpy(temp->movie.title,title);
	temp->movie.description = new char[strlen(description)+1];
	strcpy(temp->movie.description,description);
	

	temp->next = head;	//insert into the list
	head = temp;		//connect head to point to this node


	cout << "\nAnother? ";
	cin >> response; cin.ignore(100,'\n');
	
}
while ('N'!= toupper(response));

	current = head;
	while (current != NULL)
	{
		cout<<"Title: " << current->movie.title
		<<endl << current->movie.description
		<<endl <<endl;
		
		current = current->next;

	}
return 0;
}
