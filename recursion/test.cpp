#include "test.h"
using namespace std;

void build(node *& head)
{
for (int i = 0; i < 10; ++i)
{
if (head == NULL)
	{
		head = new node;
		head->data = i;
		head->next = NULL;
		return;
	}
//insert at the end
if (head->next != NULL)
{
	node * current = head;
	while (current->next != NULL)
	{
		current = current->next;	
	}
		current = new node;
		current->data = i;
		current->next = NULL;
}
}
} 


void display(node * head)
{
if (head == NULL)return;
if (head != NULL)
{
node * current = head;
while (current != NULL)
{
	cout << current->data<< " ";
	current = current->next;
}

}
}

void remove(node * head)
{
if (head!= NULL) return;
if (head != NULL)
{
	node * current = head;
	while (current != NULL)
	{
	delete head;
	head = current;
	head = head->next;
	current = current->next;
	}
}
}
