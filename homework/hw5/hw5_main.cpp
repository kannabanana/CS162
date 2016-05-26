#include "hw5.h"
/*
  SR Kanna
  CS162
  Program 5
  3/5/2014

  Purpose: This is my int main
*/

int main()
{

char cont;

do{
  housing list;							//constructor
  
  //VARIABLES
  int selection = 0;
  
  list.read_in();								//calling function to read from file
  list.display_all();							//calling function to display struct

  //get user information
  cout << "This program will match you up with your perfect housing arrangement! " << endl;
  cout << "Enter 1-4 to help prioritize what is most important to you. 1 is price. 2 is size. 3 is number of bedrooms. 4 is location. 5 is special features. ";
  cin >> selection;
  cin.ignore(100,'\n');

  list.prioritize(selection);						//calling function to prioritize user input and display matches

  cout << "Do you want to continue? Y/N. ";
  cin >> cont;
  cin.ignore(100,'\n');
}
while('Y'== toupper(cont));
return 0;
}
