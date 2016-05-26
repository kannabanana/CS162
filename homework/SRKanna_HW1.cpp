#include <iostream>
#include <cctype>

using namespace std;
int main()
{
//VARIABLES

int day=1;  //this loops through for number of  days or until the user asks to stop
int limit=5;	//this records the number of days they wish the enter
float for_high[i]; //forcasted amount
float high;	//actual amount
float for_low;
float low;
float for_rain;
float rain;
float for_wind;
float wind;
char response='n';

   cout << "How many days do you want to record the weather? ";
   cin >> limit;
   cin.ignore(100,'\n');


   while (day<=limit || response=='y')
   {	cout << "Day "<<day<<". Please enter the forcasted high: ";
	cin >> for_high[i];
	cin.ignore(100,'\n');
	
	cout << "Day "<<day<<". Please enter the actual high: ";
	cin >> high;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter the forcasted low: ";
	cin >> for_low;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter the actual low: ";
	cin >> low;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter the forcasted inches of rain: ";
	cin >> for_rain;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter actual inches  of rain: ";
	cin >> rain;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter the forcasted wind speed: ";
	cin >> for_wind;
	cin.ignore(100,'\n');

	cout << "Day "<<day<<". Please enter the wind speed: ";
	cin >> wind;
	cin.ignore(100,'\n');
	
	

	cout << "Would you like to continue to the next day? Y/N. ";
	cin >> response;
	cin.ignore(100,'\n');
	response=tolower(response);
	

	day+=1;
     }	


return 0;
}
