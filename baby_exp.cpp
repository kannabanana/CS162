#include <iostream>
using namespace std;
//SR Kanna
//CS162
//This program introduces the basic elements of C++. It experiments with for loops, while and do while

int main()
{ cout<<"Hello!" <<endl;
  float favorite=0;
  float limit=0;
  cout<<"What is your favorite number? ";
  cin>>favorite;
  cout<<"Your favorite number is: " <<favorite <<endl;
 
 if (favorite<5)
	cout<<"Your favorite number is less than 5" <<endl;
  else
	cout<<"Your favorite number is larger than 5" <<endl;

  limit=favorite+10;
  cout<<favorite<<" plus 10 is "<<limit <<endl;
  for (favorite;favorite<=limit;favorite++)
	cout<<favorite<<" ";
  return 0;
}
