#pragma once
template <typename T = int>
class Stack
{
public:
	// ��������� �����������
	Stack(int);
	~Stack();

	// ������� ��������
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
