#include <iostream>
#include <cctype>
#include <cstring>
//name and purpose
using namespace std;
int CONSTANT=5;
int SIZE=100;
void welcome(); //prototype
int  get_secret_word(char word[]);	//prototype
void display_dash(int count);
char guess();
bool again(char prompt[]);
bool  check(char word[],char guess,char result[]);

//This function compares the array of characers tofind out if hte guessed characer is in the array
bool check(char secret[],char guess, char result[])
{
	int length=strlen(secret);
	bool match=false;
	for (int i=0; i<length ; ++i)
	{
		if (secret[i]==guess)
		{	result[i]=guess;
			match=true;
		}
	}
	return 0;
}

//This function will read in the prompt and ask true or false
bool again(char prompt[])
{
	char response;
	cout << prompt;
	cin >> response;
	cin.ignore(100,'\n');
	if (toupper(response)== 'Y') return true;
	return false;
	
}

char guess()
{
	char guessed;
	do
	{cout<< "Please enter you guess: ";
	cin >> guessed;
	cin.ignore(100,'\n');
	cout << "You entered " << guessed << endl;
	}
	while(!again("\nIs this correct? "));
	return guessed;
}

//dsipaly dashes seperated by a space for readability
void display_dash(int count)
{
	for (int i=0; i<count; ++i)
		cout <<"___ ";
	cout << endl;
}

//This function prompts and reads in a secret word for hte hangman program and returns the number of characters read in.
int get_secret_word(char word[])
{
	cout << "Please enter a secret word: ";
	cin.width(SIZE);	//limits input to size-1 characters
	cin >> word;
	for (int i=0; i<1000; ++i)
		cout<<'\n';
	return strlen(word);
}	 
void welcome()	//function header
{
	char more_info="n";
	cout << "Welcome to the hangman game";
	cout << "Would you like directions? ";
	cin>>more_info;
	cin.ignore(100,'\n');
	if ("Y"==toupper(more_info))
	{
		Cout <<"\nGuess a word! You can make " << MISTAKES << "at most!"
			<<"\nLet’s have some fun!!!\n";
	}
}

int main()

{
	char secret_word[SIZE];
	int length;
	char  user_guess;
	char result[SZIE];

	welcome(); //function call
	// void welcome(); means prototype
		
	length = get_secret_word(secret_word); //informs the function to use this array
	length=get_secret_word(Secret_word);
	
	cout <<"WE GOT: "<<secret_word <<" "<<length<<endl;
		
	user_guess=guess();
	cout << user_guess;

	if (check(secret_word,user_guess,result))
	{
		cout<<"WOW-MATCH!\n";

	}
	else cout<< "TOO BAD. ";
return 0;
}

