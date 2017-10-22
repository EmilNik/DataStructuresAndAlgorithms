#pragma once
#include "Element.cpp"

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
	Element<T> *start;
	void DeleteStack();
};
