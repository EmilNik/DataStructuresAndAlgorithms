#include <iostream>
using namespace std;

#include "Stack.cpp"

int main()
{
	int number;
	Stack<> st(100);
	for (int i = 1; i < 100; i++)
	{
		st.Push(i);
		if (i % 5 == 0) 
		{
			st.Pop(number);
			cout << number << endl;
		}
		else if (i % 11 == 0) 
		{
			st.Top(number);
			cout << number << endl;
		}
	}

	st.Print();
}