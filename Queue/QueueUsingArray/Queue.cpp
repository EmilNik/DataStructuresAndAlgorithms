#include <cstdlib>
#include <iostream>
using namespace std;

#include "Queue.h"

//Some random number?
const int MAXSIZE = 20;


template <typename T>
Queue<T>::Queue(int size = MAXSIZE)
{
	if (size <= 0)
	{
		queueSize = MAXSIZE;
	}
	else
	{
		queueSize = size;
	}
	arr = new T[queueSize];
	first = 0;
	last = 0;
	length = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	deleteQueue();
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return length == 0;
}

template <typename T>
bool Queue<T>::IsFull()
{
	return length == queueSize;
}

template <typename T>
void Queue<T>::Push(const T& x)
{
	if (!IsFull())
	{
		arr[last] = x;
		last++;
		last = last % queueSize;
		length++;
	}
	else
	{
		cout << "The Queue is full.\n";
	}
}

template <typename T>
void Queue<T>::Pop(T& x)
{
	if (!IsEmpty())
	{
		x = arr[first];
		first++;
		first = first % queueSize;
		length--;
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
		x = arr[first];
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
	delete[] arr;
}
