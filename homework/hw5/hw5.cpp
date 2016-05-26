#include "hw5.h"
/*
  SR Kanna
  CS162
  Program 5
  3/5/2014

  Purpose: This is where I'm declaring my functions
*/

//This is the constructor to initialize all values
housing::housing()
{
  head = NULL; 							//initialze head to null 
}

//This is the destuctor function
housing::~housing()
{
node * current = head;						//need current pointer
while (current != NULL)						//traverse until point
	{
	current = current-> next;
	delete head;
	head = current;
	}
}

//This function is reading everything into an array of struct
void housing::read_in(void)
{
  house temp_house;
  char temp[400];
  ifstream file_in;
  file_in.open("housing.txt");					//say which file
  if(!file_in)
    return;
  else
    {
      while(!file_in.eof())				//while there's still info and it's less than the number of lines
        {
          file_in >> temp_house.price;
          file_in.ignore(100,'|');				//deliminer is |
		
          file_in >> temp_house.size;
          file_in.ignore(100,'|');
		
          file_in >> temp_house.bedroom;
          file_in.ignore(100,'|');

          file_in.get(temp,400,'|');			
          file_in.ignore(100,'|');
          temp_house.location = new char[strlen(temp)+1];		//sizes the char for the struct struct
          strcpy(temp_house.location, temp);				//copies user info into correctly sized array of struct
		
          file_in.get(temp,400,'|');
          file_in.ignore(100,'|');
          temp_house.feature1 = new char[strlen(temp)+1];
          strcpy(temp_house.feature1,temp);
	   		
          file_in.get(temp,400, '|');
          file_in.ignore(100,'|');
          temp_house.feature2 = new char[strlen(temp)+1];
          strcpy(temp_house.feature2,temp);
		
          file_in.get(temp,400, '\n');
          file_in.ignore(100,'\n');
          temp_house.feature3 = new char[strlen(temp)+1];
          strcpy(temp_house.feature3,temp);
	  
	  if(strlen(temp) > 0)
	  	insert(temp_house);					//calls function to insert into LLL
	  delete [] temp_house.feature1;
	  delete [] temp_house.feature2;
	  delete [] temp_house.feature3;
        }
    }
}

//Figuring out what the user wants
void housing::prioritize(int selection)									//argument passed in from int main
{
int low,high;
char temp[400],temp2[400],temp3[400];
  switch (selection){
  case 1:												//selection variable applies throughout switch statement
    cout << "Please enter your lower price range. ";
    cin >> low;										
    cin.ignore(100,'\n');
    cout << "Please enter your higher price range. ";
    cin >> high;									
    cin.ignore(100,'\n');
compare (low,high,selection);										//calls compare function
   break;
  case 2:
    cout << "Please enter your lowest size range. ";
    cin >> low;
    cin.ignore(100,'\n');
    cout << "Please enter your largest size preferance. ";
    cin >> high;
    cin.ignore(100,'\n'); 

  compare(low,high,selection);
    break;

  case 3:
    cout << "Please enter you lowest number of bedrooms. ";
    cin >> low;
    cin.ignore(100,'\n');
    cout << "Please enter you largest number of bedrooms. ";
    cin >> high;
    cin.ignore(100,'\n');
  compare(low,high,selection);
    break;
  case 4:
    cout << "Please enter your prefered location: ";
    cin.get(temp,400,'\n');												//changes to char
    cin.ignore(100,'\n');
    compare_char(temp);	
    break;
  case 5:
		
    cout << "Please enter your first extra feature: ";
    cin.get(temp,400,'\n');
    cin.ignore(100,'\n');
		
    cout << "Please enter your second extra feature: ";								//feature 2
    cin.get(temp2,400,'\n');
    cin.ignore(100,'\n');
		
    cout << "Please enter your third extra feature: ";								//feature 3
    cin.get(temp3,400,'\n');
    cin.ignore(100,'\n');
    compare_char2(temp,temp2,temp3);										//compare function
    break;
  }
}

//display the LLL
void housing::display_all()
{
	int i = 0;												//used for user to keep track of days
	node * current;
	if (head == NULL) return;										//don't show anything if there's nothing to show
	else
	{
		node * current = head;
		while (current != NULL)
		{
			cout << i << '\t';
			cout << current->a_house.price << '\t';
			cout << current->a_house.size << '\t';
			cout << current->a_house.bedroom << '\t';
			cout << current->a_house.location << '\t';
			cout << current->a_house.feature1 << '\t';
			cout << current->a_house.feature2 << '\t';
			cout << current->a_house.feature3 << '\n';
			current = current->next;								//traverse
			++i;
		}
	}

}
//inserts values from struct into LLL
void housing::insert(house & temp_house)
{
	//if head is empty, insert in the beginning
	if(head == NULL)
	{
	     head = new node;
	     head-> a_house.copy(temp_house);								//make sure it doesn't copy over
	     head-> next = NULL;
	}
	//if head is not empty:
	else
	{
	node * current = head;
	while (current-> next != NULL)
		current= current->next;
	current->next= new node;
	current = current->next;
	current->a_house.copy(temp_house);									//so it doesn't get replaced
	current->next = NULL;
	}
}

//copies to make sure it doesn't overwrite
void house::copy(house & var)
{
	price = var.price;
	size = var.size;
	bedroom = var.bedroom;

	location = new char[strlen(var.location)+1];								//sizing it correctly
	strcpy(location,var.location);										//copying the information 

	feature1 = new char[strlen(var.feature1)+1];								//repeats
	strcpy(feature1,var.feature1);

	feature2 = new char[strlen(var.feature2)+1];
	strcpy(feature2,var.feature2);

	feature3 = new char[strlen(var.feature3)+1];
	strcpy(feature3,var.feature3);

}

//compares user int values and outputs the matches
void housing::compare(int low,int high,int selection)
{
if (head == NULL) return;
node * current = head;												//These two variables apply to all three test cases
int i = 0;
switch (selection){

case 1:
while (current != NULL)
	{
	if(current->a_house.price >=low && current->a_house.price <=high)					//only thing different is price
	{	++i;
		if (i == 1)
			cout << "There is a match." << endl;							//displays only once
	}
	current = current->next;
	}
	break;

case 2:
while (current != NULL)
{
	if(current->a_house.size >=low && current->a_house.size <=high)						//SIZE
	{	++i;
		if (i == 1);
			cout << "There is a match." << endl;
	}
	current = current->next;
}
break;

case 3:
while (current != NULL)
{
	if(current->a_house.bedroom >=low && current->a_house.bedroom <=high)					//BEDROOM
	{	++i;
		if (i == 1)
			cout << "There is a match." << endl;
	}
	current = current->next;
	
}
	break;
}
}

void housing::compare_char(char temp[])
{
if (head == NULL) return;
node * current = head;
while (current != NULL)
{
	if(strcmp (current->a_house.location,temp)==0)								//checks if there's a match
			cout << "There is a match to your desired location." << endl;
	current = current->next;
}
}

void housing::compare_char2(char temp[],char temp2[],char temp3[])
{
if (head == NULL)return;
node * current = head;
int i = 0;
while (current !=NULL)
{
	if(strcmp (current->a_house.feature1,temp) == 0 || strcmp (current->a_house.feature1,temp2) == 0 || strcmp (current->a_house.feature1,temp3) == 0 ||
	   strcmp (current->a_house.feature2,temp) == 0 || strcmp (current->a_house.feature2,temp2) == 0 || strcmp (current->a_house.feature2,temp3) == 0 ||
	   strcmp (current->a_house.feature3,temp) == 0 || strcmp (current->a_house.feature3,temp2) == 0 || strcmp (current->a_house.feature3,temp3) == 0)
		{	
		++i;
		if (i == 1)											//Makes sure to display message only once
			cout << "There is a match! " << endl;
		}	
	current = current->next;
}
}
