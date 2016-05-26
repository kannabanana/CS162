#include <iostream>
#include <cctype>
using namespace std;
int main()
{
char grade='a';
while (grade!=toupper(grade))
{
	cout<<"Enter a grade. ";
	cin>>grade;

}
return 0;
}
