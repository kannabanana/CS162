#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
char str[] = "This is a simple string yes it is simple so simple          x";
char * pch;
int i =0;
char mispell[] = "simple";
char correct[] = "sample";
while (pch)
{
	cout << "count is: " << ++i << endl;
	pch = strstr(str,mispell);
//	cout << "PCH value: " << *pch << endl;
	printf("Pointer value of pch using percent p is: %p\n",pch);
	printf("Pointer value of pch using percent d is: %d\n",pch);
	if (pch)
	{	
	strncpy(pch,correct,6);  
	}
	puts(str);
}
return 0;
}
