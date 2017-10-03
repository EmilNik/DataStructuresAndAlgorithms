#pragma once
#include "Node.cpp"

template <typename T = int>
class Queue
{
public:
	Queue();
	~Queue();
	bool IsEmpty();
	void Push(T&);
	void Pop(T&);
	void Top(T&);
	void Print();
private:
	Node<T> *first;
	Node<T> *last;
	void DeleteQueue();
};
