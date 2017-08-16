#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(){
	top = NULL;
}

void Stack::push(int data){
	node *p = new node;
	p->data = data;
	p->next = NULL;
	if (top != NULL){
		p->next = top;
	}
	top = p;
}

int Stack::pop(){
	node *temp;
	int value;
	if (top == NULL){
		cout << "\nThe Stack is Empty" << endl;
	}
	else{
		temp = top;
		top = top->next;
		value = temp->data;
		delete temp;
	}
	return value;
}

bool Stack::isEmpty(){
	return (top == NULL);
}

void Stack::display(){
	node *p = top;
	if (top == NULL){
		cout << "\nNothing to Display\n";
	}
	else{
		cout << "\nThe contents of Stack\n";
		while (p != NULL){
			cout << p->data << endl;
			p = p->next;
		}
	}
}