/*
  SR Kanna
  CS162
  Program 5
  3/6/2014

  Purpose: The .h file contains function prototypes, a class and a structure

  Description:
  This program matches the user with possible housing based five test conditions: price, size, bedroom, location and special features. The program compares the available features and the user's conditions and presents the possible matches. The program takes in a range of values for price, size, and bedroom but exact values for location and special features.


  Algorithm:
	  I. A program to match the user input to existing data

	  A. I need to create an external file and compare user information to it
		  a. I need to iread in from an from the external file and store it in a structs
 			 1. The struct must be in the .h file before the class, because it will be a private data member of the class
 			 2. the external data will be read first in the int main so that the structure will hold it and display first
			 3. there will need to be two structs, because the struct will eventually store everything into my linear linked list
  		b. The structure will check if the file is open
			 1. create a temporary variable
			 2. have a while loop
  				i. conidtion is that as long as the information exists and i is less than the amount of lines in the file
				ii. read in the information into structure using file_in.get
				iii. using file_in.ignore ('\t')
  				iv.  have the last file_in.ignore('\n')
  			3. increment i by one
			4. Call the insert function
  		c. close file
	B. Insert into LLL
		a. Insert at the beginning of the list if head is null
			a. create new node and assign that struct value to the new node
				1. call copy function
		b. if there is a node already, add the new information to the end of the struct
			a. make sure to call the copy function while you're adding it, so you're not repeating data
	C. Copy the nodes 
		a. 
  	E. Display the LLL
		a. If there is no information, there is nothing to show
		b. go through the linear linked list until the end (NULL)
		c. display each node

	F. Constructor File
		a. initialize head to null

  	G. Get user information function
 		 a. This function's argument will be an int (1-5)
		 b. Switch value ints:
  			1. take in low values
  			2. take in high values
  				i. do cin.ignores
  			3. use a for loop to loop through the LLL to identify if the structure has any matches between the high and low for that member
  				i. output the i (to identify the house) if there is
		 c. Switch values for chars:
  			1. take in location/special features
  			2. dynamically allocate memory
			3. Calls compare function to search for loop to loop through structure to identify if the structure has any matches for that member
	I. Destructor
		a. Go through LLL and delete head's memory using two pointers
		b. need to delete all nodes
		c. go through until all nodes are deleted
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

struct house
{
  void copy(house & var);

  int price;						//This is the variable for the 
  int size;						//This is the variable for the size of the location
  int bedroom;						//This is the number of bedrooms
  char * location;					//This is the location (dynamically allocated)
  char * feature1;					//This is the first feature (dynamically allocated); 
  char * feature2;					//This is the second feature (dynamically allocated);
  char * feature3;					//This is the third feature (dynamically allocated);
};

struct node
{
	house a_house;					//this is the variable of the struct house
	node * next;					//this is the pointer to traverse next
};

class housing
{
 public:
  housing();						//This is the prototype for the constructor to initialize all values
   void insert(house & temp_house);			//Insert function to the LLL
  ~housing();		    				//Is the prototype for the  destructor 
  void read_in();           	    //This is the prototype for the function that reads in from the file and stores all values into the structure
  void prioritize(int selection);   //This is the prototype for the function to take in what the priority for the user is and match their values to the structure and displays 
  void display_all();				//This is the prototype for the function which displays the structure
  void compare(int low,int high,int seletion);	//This is the function that takes the int values and compares and finds a match
  void compare_char(char temp[]);		//This is the function that takes in the once char and compares and finds a match
  void compare_char2(char temp[],char temp2[],char temp3[]);	//This is the function that takes THREE chars and compares to find a match
 private:
  node * head;					//pointer for head
};
