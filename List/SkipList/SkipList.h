#pragma once
#include <vector>

using namespace std;

#include "Node.h"

template <typename T = int>
class SkipList {
public:
	SkipList();
	~SkipList();

	void Print() const;
	Node<T>* Find(int searchKey) const;
	void Insert(int searchKey, T newValue);
	void Delete(int searchKey);
private:
	Node<T>* first_Node;
	Node<T>* end_Node;

	int RandomLevel();
	int NodeLevel(const Node<T>*& v);
	Node<T>* MakeNode(int key, T val, int level);

	float probability;
	int maxLevel;
};
