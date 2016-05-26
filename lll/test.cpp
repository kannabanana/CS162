#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
char title[21];
node * next;

};

int count (node * head);
{
	node * current = head;
	int counter = 0;		//keep track # of items
	while (current)
	{
	// 	if (strcmp(current-->title, "Highlander");
		++counter;
		current = current ->next;
	}
	return counter;
}

int main()
{
cout << "Enter ";
count (  );

return 0;
}
