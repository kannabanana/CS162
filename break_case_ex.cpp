#include <iostream>
using namespace std;
int main()
{
 char grade='A';
 cout<<"Please enter the grade you want. ";
 cin>>grade;
 cout<<grade<<endl;
 switch(grade) {
	case 'A':cout<<"Aim High!"<<endl;
		break;
	case 'B': cout<<"Keep working at it!"<<endl;
		break;
	default:
		cout<<"You can do better than that!"<<endl;
		break;
}
 return 0;
}
