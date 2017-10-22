#pragma once
#include <vector>

using namespace std;

template <typename T>
struct Node {
	// Constructor
	Node(int k, const T& v, int level);

	int key;
	T value;

	// pointers to successor nodes
	Node* forward;
};
