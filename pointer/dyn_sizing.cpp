#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main()
{

char temp[200];
cout << "Enter a movie title: ";
cin.get(temp,200,'\n'); cin.ignore(100,'\n');

char * movie = new char[strlen(temp)+1];
strcpy(movie,temp);

cout << "Your favorite movie is: " << movie << endl;
delete [] movie;



return 0;
}
