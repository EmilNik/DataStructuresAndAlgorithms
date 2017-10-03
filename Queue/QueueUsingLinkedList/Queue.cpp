#pragma once
#include <iostream>
using namespace std;

#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
	front = rear = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	DeleteQueue();
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return rear == NULL;
}

template <typename T>
void Queue<T>::Push(T& x)
{
	Node<T> *node = new Node<T>;
	node->data = x;
	node->next = NULL;
	if (IsEmpty())
	{
		front = node;
	}
	else
	{
		rear->next = node;
	}
	rear = node;
}

template <typename T>
void Queue<T>::Pop(T& x)
{
	if (!IsEmpty())
	{
		Node<T> *node = front;
		x = node->data;
		if (node == rear)
		{
			rear = NULL;
			front = NULL;
		}
		else
		{
			front = node->next;
		}

		delete node;
	}
	else
	{
		cout << "The Queue is empty.\n";
	}
}

template <typename T>
void Queue<T>::Head(T& x)
{
	if (!IsEmpty())
	{
		x = front->data;
	}
	else
	{
		cout << "The Queue is empty.\n";
	}
}

template <typename T>
void Queue<T>::Print()
{
	T x;
	while (!IsEmpty())
	{
		Pop(x);
		cout << x << " ";
	}
	cout << endl;
}

template <typename T>
void Queue<T>::DeleteQueue()
{
	T x;
	while (!IsEmpty())
	{
		Pop(x);
	}
}
