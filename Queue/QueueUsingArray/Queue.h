#pragma once
template <typename T = int>
class Queue
{
public:
	Queue(int);
	~Queue();

	bool IsEmpty();
	bool IsFull();
	void Push(const T&);
	void Pop(T&);
	void Top(T&);
	void Print();
private:
	T* arr;
	void DeleteQueue();
	int queueSize;
	int first;
	int last;
	int length;
};

