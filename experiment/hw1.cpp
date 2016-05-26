/* 
SR Kanna
CS162
Program #1
1.22.2014

PURPOSE:

This purpose of this program is to compare the focasted weather and the actual weather for a period for 5 days (or shorter). The program will
calculate the average, low and high for each cateogry as well.

ALGORITHM: 

I. The algorithm's function will compare the focasted weather and the actual weather, record the highest/lowest weather and weekly average.

	A. The program will compare the forcasted and actual weather in four categories: rain, wind, high and low temperature.

		a. I will calculate the average of each of the categories by using an a sum array and average array.
		b. I used a margin of error process to compare the forcasted and actual weather results.
		c. If the forcasted results were larger than the actual weather, than the actual weather was subtracted from the forcasted.
		d. If the actual weather was larger than the forcasted weather, than the forcasted weather was subtracted from the actual.

	B. The program will keep track of the low and high temperature through two arrays.

		a. Each element of the array will be assigned to a category.
		b. As the user inputs data, the existing initialized data will be compared.
		c. If the data is greater/less than desired, the initialized data will replaced the initialized data.
		d. This process will repeat until the desired result is aquired.
*/

#include <iostream>
#include <cctype>

using namespace std;
int main()

{

//VARIABLES

int rain[5] = {0,0,0,0,0};		//Array to keep track of inches of rain for period of five days
int for_rain[5] = {0,0,0,0,0};		//Array to keep track of inches of forcasted rain for period of five days
int wind[5] = {0,0,0,0,0};		//Array to keep track of mph of wind for period of five days
int for_wind[5] = {0,0,0,0,0};		//Array to keep track of forcasted mph of wind for period of five days
int hot[5] = {0,0,0,0,0};		//Array to keep track of hot weather for 5 days
int for_hot[5] = {0,0,0,0,0};		//Array to keep track of forcasted hot weather for 5 days
int cool[5] = {0,0,0,0,0};		//Array to keep track of cool weather for 5 days
int for_cool[5] = {0,0,0,0,0};		//Array to keep track of forcasted weather for 5 days

int sum[9] = {0,0,0,0,0,0,0,0,0};	//Array to keep track of sum of all the days for each category

int average[9] = {0,0,0,0,0,0,0,0};	//Array to keep track of each average for each category

char response = 'y';			//Var to keep while/do while repeating

char name[30];				//Var for user name

int highest[10] = {0,0,0,0,0,0,0,0,0};	//Array to keep track of highest data input for each category
int lowest[10] = {100000,100000,1000000,1000000,1000000,1000000,100000,10000000,1000000};	//Array to keep track of lowest data input for each cateogry

cout << "\nHello. What is your name? ";
cin.get(name,18,'\n');
cin.ignore (100, '\n');
cout << '\n';
cout << "Hello " << name << ". This program will evaluate the weather for a 5 days and compare it to the forcasted weather. \n " << endl;


do

{	
	int x = 0;	//Var to help put data into appropriate array locations. Initialized here for do while.
	int i = 1;	//Var to help day. Initialized here for do while.

	while( x <= 4 && 'Y' == toupper(response))

	{
		cout << "How many inches of rain for day " << i << "? ";
		cin >> rain[x];	
		cout << '\n';
		cout << "You entered: " << rain[x] << endl;
		sum[0] += rain[x];
		if (highest[0] <= rain[x])
			highest[0] = rain[x];
		if (lowest[0] >= rain[x])
			lowest[0] = rain[x];		
	
		cout << "What's the forcasted inches of rain for day " << i << "? ";
		cin >> for_rain[x];
		cout << '\n';
		cout << "You entered: " << for_rain[x] << endl;
		sum[1] += for_rain[x];
		if (highest[1] <= for_rain[x])
			highest[1] = rain[x];
		if (lowest[1] >= rain[x])
			lowest[1] = rain[x];

		
		cout << "What's the mph of wind for day " << i << "? ";
		cin >> wind[x];
		cout << '\n';
		cout << "You entered: " << wind[x] << endl;
		sum[2] += wind[x];
		if (highest[2]<=wind[x])
			highest[2] = wind[x];
		if (lowest[1] >= wind[x])
			lowest[2] = wind[x];

		cout << "What's the forcasted mph of wind for day " << i << "? ";
		cin >> for_wind[x];
		cout << '\n';
		cout << "You entered: " << for_wind[x] << endl;
		sum[3] += for_wind[x];
		if (highest[3] <= for_wind[x])
			highest[3] = for_wind[x];
		if (lowest[3] >= for_wind[x])
			lowest[3] = for_wind[x];

		cout << "What's the high in F for day " << i << "? ";
		cin >> hot[x];
		cout <<'\n';
		cout << "You entered: " << hot[x] << endl;
		sum[4] += hot[x];
		if (highest[4] <= hot[x])
			highest[4] = hot[x];
		if (lowest[4] >= hot[x])
			lowest[4] = hot[x];

		cout << "What's the forcasted high in F for day " << i << "? ";
		cin >> for_hot[x];
		cout << '\n';
		cout << "You entered: " << for_hot[x] << endl;
		sum[5] += for_hot[x];
		if (highest[5] <= for_hot[x])
			highest[5] = for_hot[x];
		if (lowest[5] >= for_hot[x])
			lowest[5] = for_hot[x];


		cout << "What's the low in F for day " << i << "? ";
		cin >> cool[x];
		cout << '\n';
		cout << "You entered: " << cool[x] << endl;
		sum[6] += cool[x];
		if (highest[6] <= cool[x])
			highest[6] = cool[x];
		if (lowest[6] >= cool[x])
			lowest[6] = cool[x];

		cout << "What's the forcasted low in F for day " << i << "? ";
		cin >> for_cool[x];
		cout << '\n';
		cout << "You entered: " << for_cool[x] << endl;
		sum[7] += for_cool[x];
		if (highest[7] <= for_cool[x])
			highest[7] = for_cool[x];
		if (lowest[7] >= for_cool[x])
			lowest[7] = for_cool[x];

		cout << "Do you want to continue? Y/N. ";
		cin >> response;
		cin.ignore(100,'\n');

		++i;
		++x;
	}

	cout << '\n';

	average[0] = sum[0]/(x);
        cout << "The average amount of rain is: " << average[0] << endl;
	cout << "The highest amount of rain is: " << highest[0] << endl;
	cout << "The lowest amoutn of rain is: " << lowest[0] << endl;
	cout << '\n' << endl;


	average[1] = sum[1]/(x);
	cout << "The forcasted average amount of rain is: " << average[1] << endl;
	cout << "The highest forcasted amount of rain is: " << highest[1] << endl;
	cout << "The lowest forcasted amount of rain is: " << lowest[1] << endl;
	cout << '\n' << endl;

	if (average[1]>average[0])
		cout << "The margin of error is: " << average[1]-average[0] << '\n';
	else cout << "The margin of error is: " << average[0]-average[1] << '\n';
	cout << '\n';
	
	average[2] = sum[2]/(x);
	cout << "The average amount of wind is: " << average[2] << endl;
	cout << "The highest amount of wind is: " << highest[2] << endl;
	cout << "The lowest amount of wind is: " << lowest[2] << endl;
	cout << '\n' << endl;

	average[3] = sum[3]/(x);
	cout << "The average forcasted amount of wind is: " << average[3] << endl;
	cout << "The highest forcasted wind is: " << highest[3] << endl;
	cout << "The lowest forcasted wind is: " << lowest[3] << endl;
	cout << '\n' << endl;

	if (average[3]>average[2])
                cout << "The margin of error is: " << average[3]-average[2] << '\n';
        else cout << "The margin of error is: " << average[2]-average[3] << '\n';
	cout << '\n';

	average[4] = sum[4]/(x);
	cout << "The average high temperature is: " << average[4] << endl;
	cout << "The highest high temperature is: " << highest[4] << endl;
	cout << "The lowest high temperature is: " << lowest[4] <<endl;
	cout << '\n' << endl;

	average[5] = sum[5]/(x);
	cout << "The forcasted average high temperature is: " << average[5] << endl;
	cout << "The highest forcasted high temperature is: " << highest[5] << endl;
	cout << "The lowest forcasted high temperature is: " << lowest[5] << endl;
	cout << '\n' << endl;
	
	 if (average[5]>average[4])
                cout << "The margin of error is: " << average[5]-average[4] << '\n';
         else  cout << "The margin of error is: " << average[4]-average[5] << '\n';
	 cout << '\n';

	average[6] = sum[6]/(x);
	cout << "The average low temperature is: " << average[6] << endl;
	cout << "The highest low temperature is: " << highest[6] << endl;
	cout << "The lowest low temperature is: " <<lowest[6] << endl;
	cout << '\n' << endl;

	average[7] = sum[7]/(x);
	cout << "The average forcasted low temperature is: " << average[7] << endl;
	cout << "The highest low temperature is: " << highest[7] << endl;
	cout << "The lowest low temperature is: " << lowest[7] << endl;
	cout << '\n' << endl;

	if (average[7]>average[6])
		cout << "The margin of error is: " << average[7]-average[6] << '\n';
	else  cout << "The margin of error is: " << average[6]-average[7] << '\n';
	cout << '\n';

	cout << "Would you like to start all over? Y/N. ";
	cin >> response;
	cin.ignore(100,'\n');

}

while('Y' == toupper(response));

}
