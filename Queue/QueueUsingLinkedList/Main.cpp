#include <iostream>
using namespace std;

#include "Queue.cpp"

int main()
{
	int number;
	Queue<> queue;
	for (int i = 1; i < 120; i++)
	{
		queue.Push(i);
		if (i % 5 == 0)
		{
			queue.Pop(number);
			cout << number << endl;
		}
		else if (i % 11 == 0)
		{
			queue.Head(number);
			cout << number << endl;
		}
	}

	queue.Print();
}
