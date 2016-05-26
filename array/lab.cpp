#include <iostream>
#include <cstring>
#include <cctype>
//This program will ask the user to enter a something else if what they entered isn't one word.

using namespace std;
int main ()
{
//Variables
char magic_word[4]={'h','i','!'};
char word[4]={'h','i','!'};

		do {
		cout << "Enter a word: ";
		cin >> word;
		cin.ignore(100,'\n');
		}
		while (strcmp(magic_word,word)!=0);
return 0;
}
