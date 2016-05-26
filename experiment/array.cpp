#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
//declaring variables
char letters[100];

	cout << "Enter your class names: ";
	cin.get(letters,100,'\n');
	cin.ignore(100,'\n');
	cout << letters <<". "<<endl;
	cout << letters[0] <<endl;
	cout << letters[1] <<endl;
	cout << letters[2] <<endl;

return 0;
}
