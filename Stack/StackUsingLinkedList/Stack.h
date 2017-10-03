#pragma once
#include "Node.cpp"

template <typename T = int>
class Stack 
{
public:
	Stack();
	~Stack();
	bool IsEmpty();
	void Push(T&);
	void Pop(T&);
	void Top(T&);
	void Print();
	int Length();
private:
	Node<T> *start;
	void DeleteStack();
};