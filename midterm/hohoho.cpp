#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main ()

{
char arr1[20];
char arr2[20];
char arr3[20];

cout << "Enter array: ";
cin >> arr1;
cin.ignore(100,'\n');
cout << "Enter array: ";
cin >> arr2;
cin.ignore(100,'\n');

int x = 0;
int len = strlen(arr1);
int len2 = strlen(arr2);
int count =0;
char letter;
for (int i = 0; i < len; ++i)
{
	while (x < len)
	{
		if (arr1[i] == arr2[x])
			{			
			letter = arr3[count];
			++count;							
			}

		++x;
	}
}

cout << arr3 << endl;
return 0;

}
