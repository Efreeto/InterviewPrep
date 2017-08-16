
#include <iostream>
#include "Node.h"
#include "Queue.h"
using namespace std;

void Queue::display()
{
	node* p = new node;
	p = front;
	if (!front)
		cout << "\nNothing to Display\n";
	else
	{
		while (p)
		{
			cout << endl << p->data;
			p = p->next;
		}
	}
}

void Queue::enqueue(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (!front)
		front = temp;
	else
		rear->next = temp;
	rear = temp;
}

int Queue::dequeue()
{
	node *temp = new node;
	int value;
	if (isEmpty())	//if(!front) if(front==NULL) all work
		cout << "\nQueue is Empty\n";
	else
	{
		temp = front;
		value = temp->data;
		front = front->next;
		delete temp;
	}
	return value;
}

bool Queue::isEmpty()
{
	return (front == NULL);
}
