#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"

// Параметричен конструктор
template <typename T>
Stack<T>::Stack(int size)
{
}

// Деструктор
template <typename T>
Stack<T>::~Stack()
{
}

// Конструктор за присвояване
template <typename T>
Stack<T>::Stack(const Stack<T>& stack)
{
}

// Оператор за присвояване
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{

}

// Проверява дали стекът е празен и връща булева стойност
template <typename T>
bool Stack<T>::IsEmpty()
{
}

// Проверява дали стекът е пълен и връща булева стойност
template <typename T>
bool Stack<T>::IsFull()
{
}

// Намира върха на стека, ако не е празен, и го записва в параметъра x
template <typename T>
void Stack<T>::Top(T& x)
{
}

// Добавя параметъра x в стека, ако не е пълен
template <typename T>
void Stack<T>::Push(T& x)
{
}

// Изключва елемент от стека, ако не е празен, и го записва в параметъра x
template <typename T>
void Stack<T>::Pop(T& x)
{
}

// Принтира на екрана всички елементи от стека, като го разрушава
template <typename T>
void Stack<T>::Print()
{
}