/*
  SR Kanna
  CS162
  Program 4
  3/6/2014

  Purpose: The .h file contains function prototypes, a class and a structure

  Description:
  This program matches the user with possible housing based five test conditions: price, size, bedroom, location and special features. The program compares the available features and the user's conditions and presents the possible matches. The program takes in a range of values for price, size, and bedroom but exact values for location and special features.


  Algorithm:
  I. A program to match the user input to existing data
  A. I need to create an external file and compare user information to it
  a. I need to read in from an from the external file and store it in an array of structs
  1. The struct must be in the .h file before the class, because it will be a private data member of the class
  2. the external data will be read first in the int main so that the structure will hold it and display first
  b. The array of structure will check if the file is open
  1. have a while loop
  i. conidtion is that as long as the information exists and i is less than the amount of lines in the file
  ii. read in the information into structure using file_in.get
  iii. using file_in.ignore ('\t')
  iv.  have the last file_in.ignore('\n')
  2. increment i by one
  c. close file
  B. Display File
  a. after reading in everything into the structure, display the array of structure
  b. use a while loop
  1. initialize new local variable
  2. cout i 
  3. cout each member of the object spaced by a tab
  4. seperate with a new line
  5. increment i by one
  C. Constructor File
  a. Takes in an argument of char file
  b. copies the name of the file from one to the other (for the external file)
  c. set private data members to null (char arrays) or zero
  D. Get user information function
  a. This function's argument will be an int (1-5)
  b. The int will correlate to a switch value depending on what they want to prioritize on
  c. Switch value ints:
  1. take in low values
  2. take in high values
  i. do cin.ignores
  3. use a for loop to loop through structure to identify if the array of structure has any matches between the high and low for that member
  i. output the i (to identify the house) if there is
  d. Switch values for chars:
  1. take in location/special features
  2. dynamically allocate memory
  3. Use for loop to loop through structure to identify if the array of structure has any matches for that member
  1. output the i (to identify the house) if there is
  4. delete memory
  E. Destructor
  a. use a for loop to deallocate memory
  b. for each pointer memory which is allocated	- equivilent for each occurance of new

*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

struct house
{
  int price;						//This is the variable for the 
  int size;						//This is the variable for the size of the location
  int bedroom;						//This is the number of bedrooms
  char * location;					//This is the location (dynamically allocated)
  char * feature1;					//This is the first feature (dynamically allocated); 
  char * feature2;					//This is the second feature (dynamically allocated);
  char * feature3;					//This is the third feature (dynamically allocated);
};

class housing
{
 public:
  housing(const char filename[]);	//This is the prototype for the constructor to initialize all values
  ~housing();		        //This is the prototype for the  destructor 
  void read_in();               //This is the prototype for the function that reads in from the file and stores all values into the structure
  void prioritize(int selection);   //This is the prototype for the function to take in what the priority for the user is and match their values to the structure and displays 
  void display_all();				//This is the prototype for the function which displays the structure
 private:
  house list[4];					//this is the object member of the struct 
  int low;					//the lowest possible value the user would want to enter
  int high;					//the highst possible value the user would want to enter
  char m_filename[25];				//char array for constructor file
  char temp[400];					//temporary variable to store information for dynamically allocated
  char temp2[400];				//temporary variable to store information for dynamically allocated
  char temp3[400];				//temporary variable to store information for dynamically allocated
};
