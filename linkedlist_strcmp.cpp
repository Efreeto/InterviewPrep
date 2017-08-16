/* http://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/ */
#include <stdio.h>

// Linked list Node structure
struct Node
{
	char c;
	Node* next;
};

// Function to create newNode in a linkedlist
Node* newNode(char c)
{
	Node* temp = new Node;
	temp->c = c;
	temp->next = nullptr;
	return temp;
}

Node* convert(char* str)
{
	if (*str == NULL)	// check for end of string. same as (*str == 0), (!*str), but not as (str == nullptr)
	{
		return nullptr;	// return null pointer to mark the end of linked list
	}
	Node* temp = newNode(*str);
	temp->next = convert(str+1);
	return temp;
}

int strcmp(Node* list1, Node* list2)
{
	// Traverse both lists. Stop when either end of a linked 
	// list is reached or current characters don't match
	while (list1 && list2 && list1->c == list2->c)
	{
		list1 = list1->next;
		list2 = list2->next;
	}

	//  If both lists are not empty, compare mismatching
	//  characters
	if (list1 && list2)
		return (list1->c > list2->c) ? 1 : -1;

	// If either of the two lists has reached end
	if (list1 && !list2) return 1;
	if (list2 && !list1) return -1;

	// If none of the above conditions is true, both 
	// lists have reached end 
	return 0;
}

int main()
{
	char str1[] = "geeksa";
	char str2[] = "geeks";
	Node* list1 = convert(str1);
	Node* list2 = convert(str2);
	printf("%d\n", strcmp(list1, list2));
}

/*
Input: list1 = g->e->e->k->s->a
list2 = g->e->e->k->s->b
Output: -1

Input: list1 = g->e->e->k->s->a
list2 = g->e->e->k->s
Output: 1

Input: list1 = g->e->e->k->s
list2 = g->e->e->k->s
Output: 0
*/