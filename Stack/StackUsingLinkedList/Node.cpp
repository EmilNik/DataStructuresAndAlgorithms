#pragma once
template <typename T = int>
struct Node
{
	T data;
	Node<T>* next;
};
