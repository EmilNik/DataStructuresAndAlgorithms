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
	void Head(T&);
	void Print();
private:
	Node<T> *front;
	Node<T> *rear;
	void DeleteQueue();
};
