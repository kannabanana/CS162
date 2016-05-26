#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main ()
{
int grade = 0;
int length;
cout << "How many scores are there? ";
cin >> length;
cin.ignore(100,'\n');

float * scores;
float greade = 0.0;

scores = new float[length];
cout << "Please enter " <<length << " scores: ";
for (int i=0; i <length; ++i)
{
	cin >> scores[i];
	cin.ignore(100,'\n');
}

for (int i =0; i<length;++i)
{
	grade+=scores[i];
}
grade/=length;

cout << grade << endl;
delete[]scores;

return 0;
}
