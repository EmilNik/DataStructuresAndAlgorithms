#include "Node.h"

template <typename T = int>
Node<T>::Node(int k, const T& v, int level)
	: key(k), value(v)
{
	for (int i = 0; i < level; ++i)
	{
		forward = NULL;
	}
}
