#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"

// ������������ �����������
template <typename T>
Stack<T>::Stack(int size)
{
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
}

// ����������� �� �����������
template <typename T>
Stack<T>::Stack(const Stack<T>& stack)
{
}

// �������� �� �����������
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{

}

// ��������� ���� ������ � ������ � ����� ������ ��������
template <typename T>
bool Stack<T>::IsEmpty()
{
}

// ��������� ���� ������ � ����� � ����� ������ ��������
template <typename T>
bool Stack<T>::IsFull()
{
}

// ������ ����� �� �����, ��� �� � ������, � �� ������� � ���������� x
template <typename T>
void Stack<T>::Top(T& x)
{
}

// ������ ���������� x � �����, ��� �� � �����
template <typename T>
void Stack<T>::Push(T& x)
{
}

// �������� ������� �� �����, ��� �� � ������, � �� ������� � ���������� x
template <typename T>
void Stack<T>::Pop(T& x)
{
}

// �������� �� ������ ������ �������� �� �����, ���� �� ���������
template <typename T>
void Stack<T>::Print()
{
}