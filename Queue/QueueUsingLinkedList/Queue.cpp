#pragma once
#include <iostream>
using namespace std;

#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
	first = last = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	DeleteQueue();
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return last == NULL;
}

template <typename T>
void Queue<T>::Push(T& x)
{
	Node<T> *node = new Node<T>;
	node->data = x;
	node->next = NULL;
	if (IsEmpty())
	{
		first = node;
	}
	else
	{
		last->next = node;
	}
	last = node;
}

template <typename T>
void Queue<T>::Pop(T& x)
{
	if (!IsEmpty())
	{
		Node<T> *node = first;
		x = node->data;
		if (node == last)
		{
			last = NULL;
			first = NULL;
		}
		else
		{
			first = node->next;
		}

		delete node;
	}
	else
	{
		cout << "The Queue is empty.\n";
	}
}

template <typename T>
void Queue<T>::Top(T& x)
{
	if (!IsEmpty())
	{
		x = first->data;
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
