#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);

	bool IsEmpty() const;
	void IterStart(Node<T>* = NULL);
	Node<T>* Iter();
	void Add(const T&);
	void InsertAfter(Node<T>*, const T&);
	void InsertBefore(Node<T>*, const T&);
	void DeleteAfter(Node<T>*, const T&);
	void DeleteBefore(Node<T>*, const T&);
	void DeleteNode(Node<T>*, const T&);
	void Print() const;
	int Length() const;
	void Concat();
	void Reverse();
private:
	Node<T> *start;
	Node<T> *end;
	Node<T> *current;
	void CopyList(const LinkedList&);
	void DeleteList();
};

