#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	start = end = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	DeleteList();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	CopyList(list);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
	if (!this != &list)
	{
		DeleteList();
		CopyList(list);
	}

	return *this;
}

template <typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& list)
{
	start = end = current = NULL;
	Node<T> *node = list.start;
	while (node)
	{
		Add(node->data);
		node = node->next;
	}
}

template <typename T>
void LinkedList<T>::DeleteList()
{
	Node<T> *node;
	while (start)
	{
		node = start;
		start = start->next;
		delete start;
	}

	end = NULL;
}

template <typename T>
void LinkedList<T>::IterStart(Node<T> *node)
{
	if (node)
	{
		current = node;
	}
	else
	{
		current = start;
	}
}

template <typename T>
Node<T>* LinkedList<T>::Iter()
{
	Node<T> *node = current;
	if (current)
	{
		current = current->next;
	}

	return node;
}

template <typename T>
void LinkedList<T>::Add(const T& element)
{
	Node<T> *node = end;
	end = new Node<T>;
	end->data = x;
	end->next = NULL;
	if (node)
	{
		node->next = end;
	}
	else
	{
		start = end;
	}
}