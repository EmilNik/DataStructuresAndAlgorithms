#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"

// Constructor
template <typename T>
Stack<T>::Stack()
{
	start = NULL;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
	DeleteStack();
}

// Deletes stack
template <typename T>
void Stack<T>::DeleteStack()
{
	Node<T> *n;
	while (start)
	{
		n = start;
		start = start->next;
		delete n;
	}
}

// Checks if stack is empty and returns bool
template <typename T>
bool Stack<T>::IsEmpty()
{
	return start == NULL;
}

// Adds x in stack
template <typename T>
void Stack<T>::Push(T& x)
{
	Node<T>* n = start;
	start = new Node<T>;
	start->data = x;
	start->next = n;
}

// Removes the top element of stack and saves it into x
template <typename T>
void Stack<T>::Pop(T& x)
{
	if (!IsEmpty())
	{
		x = start->data;
		Node<T>* n = start;
		start = start->next;
		delete n;
	}
	else
	{
		cout << "The stack is empty.\n";
	}
}

// Writes the top of the stack in x
template <typename T>
void Stack<T>::Top(T& x)
{
	if (!IsEmpty())
	{
		x = start->data;
	}
	else
	{
		cout << "The stack is empty.\n";
	}
}

// Prints all elements of the stack and empties it
template <typename T>
void Stack<T>::Print()
{
	T x;
	while (!IsEmpty())
	{
		Pop(x);
		cout << x << " ";
	}
	cout << endl;
}

// Returns length of stack
template <typename T>
int Stack<T>::Length()
{
	Node<T>* n = start;
	int count = 0;
	while (n)
	{
		count++;
		n = n->next;
	}
	return count;
}
