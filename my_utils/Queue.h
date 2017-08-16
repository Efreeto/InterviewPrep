#include "Node.h"
#ifndef NULL
#define NULL 0
#endif

class Queue
{
	node* front = NULL;
	node* rear = NULL;

public:
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	void display();
};