#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//SR Kanna, CS 152, 
//Read, echo and confirm info about a video

const int TITLE =  21;
const int DESC =  57;
const int CAT = 16;
const int VIDEOS = 10;

//Structures to group different video members

//prototype
//prompt and read in an array of characters
//of a maximum size and plae what was read into result

int main()
{

	//create a video's incofmation
	char title[TITLE];
	char description[DESC];
	char category[CAT];
	int file_size;

	//Get in a video's information
	read("Please enter title: ", TITLE, title);
	read("Please enter description: ", DESC,description);
	read("Plesa enter category: ", CAT, category);
	cout << "Please enter the file_size: ";
	cin >> file_size;
	cin.ignore(100, '\n');
	
	//Display all of the received info:
	cout << title <<'\t' << description << '\t' << category << '\t' << "File size " << file_size <<endl;


return 0;

}



//Prompt and read in an array of characteres

void read(char prompt[], int size, char result[])
{
	cout << prompt;
	cin.get(result, size,'\n');
	cin.ignore(100,'\n');
}
