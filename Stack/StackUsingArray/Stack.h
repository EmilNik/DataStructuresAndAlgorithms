#pragma once
template <typename T = int>
class Stack
{
public:
	// Канонично представяне
	Stack(int);
	~Stack();

	// Основни операции
	bool IsEmpty();
	bool IsFull();
	void Push(const T&);
	void Pop(T&);
	void Top(T&);
	void Print();
private:
	int stackSize;
	int stackTop;
	T* arr;
	void deleteStack();
};
