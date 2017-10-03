#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"

//Some random number?
const int MAXSIZE = 20;

// Explicit constructor
template <typename T>
Stack<T>::Stack(int size = MAXSIZE)
{
	if (size <= 0)
	{
		stackSize = MAXSIZE;
	}
	else
	{
		stackSize = size;
	}

	arr = new T[stackSize];
	stackTop = -1;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
	deleteStack();
}

// Deletes stack
template <typename T>
void Stack<T>::DeleteStack()
{
	delete[] arr;
}

// Checks if stack is empty and returns bool
template <typename T>
bool Stack<T>::IsEmpty()
{
	return stackTop == -1;
}

// Checks if stack is full and returns bool
template <typename T>
bool Stack<T>::IsFull()
{
	return stackTop == stackSize - 1;
}

// Writes the top of the stack in x
template <typename T>
void Stack<T>::Top(T& x)
{
	if (!IsEmpty())
	{
		x = arr[stackTop];
	}
	else
	{
		cout << "The stack is empty.\n";
	}
}

// Adds x in stack
template <typename T>
void Stack<T>::Push(const T& x)
{
	if (!IsFull())
	{
		stackTop++;
		arr[stackTop] = x;
	}
	else
	{
		cout << "The stack is full.\n";
	}
}

// Removes the top element of stack and saves it into x
template <typename T>
void Stack<T>::Pop(T& x)
{
	if (!IsEmpty())
	{
		x = arr[stackTop];
		stackTop--;
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