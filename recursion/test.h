#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
	int data;
	node * next;
};

//declare functions here:
void build(node *& head);
void display(node * head);
void remove(node *& head);
