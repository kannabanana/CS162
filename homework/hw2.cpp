#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

/*
SR Kanna
kannasr@pdx.edu
Program #2
1/29/2014

PURPOSE:

The purpose of this program is correct the basic mistakes the user may make, similar to a word document, without the hassle of it. It will capitalize the first letter the user enters, as well as after every sentence. It will ask the user to enter a mispelled word and the correct spelling. This program will also add two spaces after every period and repeat the entire process again if the user so desires.

ALGORITHM:

I. Mini Word Document Breakdown:

	A. The first function would deal with capitalizing.
		a. I needed to capitalize the first letter of the paragraph
			i. I had two arrays.
				a. The first letter can be indexed to zero, since the input buffer would ignore any whitespaces (tabs) entered by the user
			ii. I needed to assign the index zero the first array to the function call
			iii. The function would assign a toupper the first character of the origional array that the user inputed into.
		b. The second part of the function was to capitalize new sentences. The common syntax of of a new syntax is an !.?
			i. I used a for loop to go through to find each punctiation.
			iii. Once the program found one, it indexed to the next couple location (because of a space) and capitalized it.
		c. Finally, I strcpyied the two arrays to match at the end of the function.
	B. The second function dealt with adding additional spaces after the period.
		a. The function has a for loop to go through each element of the origional paragraph
		b. If the origional index does not equal a period, then each element is copied into the output array
		c. If the sequential index equals a period, it enters an else statement.
			i. The else declares the i to equal j.
				a. two variables because the output array will be larger than the paragraph array.
			ii. the first spot in the output array equals a period.
			iii. the second spot in the output array equals a space.
			iv. i is moved up an increment, because otherwise it equals a space
				a. it's traditional practice to leave a space after a period.
		d. The for loop continues until the 300th character.
	C. The third function replaced words if the user entered a misspelling.
		a. This function is second because all gramatical corrections have been made to output without interfering with spaces.
		b. This function takes in the output function, the misspelled word, and the correct word
		c. I assigned a pointer location to the misspelled location.
		d. To keep the pointer replacing each occurance of the mispelled word and stop at the null occurance, I had a while loop.
			i. It's condition going until null
			ii. It's also conditional that both lengths of the correct and incorrect word are equivilent.
		e. The function uses strstr to search for the misspelled word in the output function
		f. It outputs the final result (puts function) when finished
	D. The last function repeated the entire process if the user wanted to.
		a. This bool function was taught in the lab4
	E. The sequence of how the functions are called must be specific
		a. Replacing the words are the most critical or sensitive, so it must be called first.
		b. Adding spaces is called second, because the array size is altered.
		c. The capitalization is called third, because the user may want to change the first word.
*/

using namespace std;

//PROTOTYPES:

void capital(char output[]);							//Prototype for function to capitalize first letter and new sentences
void twospaces(char paragraph[],char output[]); 				//Prototype for function to add two spaces after a period is encountered
void replaceword(char output[],char mispell[],char correct[]);			//Prototype for function to replace misspelled word with correct word
bool again();  									//Prototype for function to repeat paragraph process all over


int main()

{

	char paragraph[300];							//origional array which user enter information into
	char output[300];							//array which things are manipulated
	char mispell[20];							//array to keep misspelled word in 
	char correct[20];							//array to keep correctly spelled word in
	
do
{
	for (int i = 0; i < 300; ++i)							//for loop to initialize both arrays so user can enter information
	{	
		paragraph[i] = '\0';
		output[i] = '\0';
	}	

		cout << "Hello! Please enter your text (less than 300 characters please) "
	     	<< "and then enter # when you are done. " << endl << endl; 
		cin.get(paragraph,300,'\n');
		cin.ignore(100,'\n');
	
				
		cout << "Please enter your mispelled word: ";			//geting info for misspelled
		cin >> mispell;							
		cin.ignore(100,'\n');
		
		cout << "Please enter the correct spelling: ";
		cin >> correct;							//getting info for correct
		cin.ignore(100,'\n');

		twospaces(paragraph,output);					//calling function to add two spaces
		replaceword(output,mispell,correct);				//calling function to replace word
		capital(output);						//calling function to capitalize first word and letter
		
		cout << output << endl;
}

while (again());
return 0;
}

//Function to capitalize the first letter after !.?



//Function to add two spaces after each period

void twospaces(char paragraph[], char output[])				//
{
	int i,j;
	for (i = 0, j = 0; i < strlen(paragraph); ++i,++j)		//initializes both i and j to both arrays to index through
	{	
		output[j] = paragraph[i];				//copies every character into second array
		if (paragraph[i] == '.')				//determines if the character is an index
			output[++j] = ' ';				//moves index over and assigns a space
	}
}


////Function to replace misspelled word with correct one

void replaceword (char output[],char mispell[],char correct[])
{

int length = strlen(correct);						//going through to identify the length of the arrays
int length2 = strlen(mispell);

if (length == length2)
{
	char * mispell_location;
	mispell_location = strstr (output,mispell);
	while (mispell_location)					//while it's not equal to NULL
 	{ 		
		strncpy (mispell_location,correct,length);		
		mispell_location = strstr (output,mispell);
	}
	
}
else
{
	cout << "Sorry. Your word lengths were different. " << endl;
}
}



//Function to repeat paragraph
void capital(char output[])
{
int x;
output[0] = toupper(output[0]);							//capitalizing first letter of paragraph
for (int i = 0; i < 300; ++i)
{
	if (output[i] == '!' || output[i] == '?')
		{
			output[i+2] = toupper(output[i+3]);				//+2 because it's customary to enter a space after ending punctuation.
		}	
	if (output[i] == '.')
		output[i+3] = toupper(output[i+3]);
} 	
}


bool again()
{
	char response;

	cout << "Do you want to continue? Y/N. ";
	cin >> response;
	cin.ignore(100,'\n');
	response = toupper(response);

	return ('Y' == response);
}
