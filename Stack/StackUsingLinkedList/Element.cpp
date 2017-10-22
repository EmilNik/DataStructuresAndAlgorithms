#pragma once
template <typename T = int>
struct Element
{
	T data;
	Element<T>* next;
};
