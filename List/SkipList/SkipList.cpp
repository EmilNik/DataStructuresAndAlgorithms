//using namespace std;

#include "SkipList.h"

template <typename T>
SkipList<T>::SkipList()
	: probability(0.5), maxLevel(16)
{
	// Initialize the startNode of the skip list

	// smallest possible key
	int startNodeKey = numeric_limits<int>::min();
	startNode = new Node<T>(startNodeKey, 0, maxLevel);

	// Initialize the last element of the list

	// largest possible key
	int endNodeKey = numeric_limits<int>::max();
	endNode = new Node(endNodeKey, NULL, maxLevel);

	// Connect start to end
	// connect all the levels/forward pointers of the startNodeer to endNode
	for (size_t i = 0; i < startNode->forward.size(); ++i)
	{
		startNode->forward[i] = endNode;
	}
}

template <typename T>
SkipList<T>::~SkipList()
{
	delete startNode;
	delete endNode;
}

// Helper functions
/*
Function: randomLevel()
Use: implicit in class SkipList
It generates node levels in the range
[1, maxLevel).

It uses rand() scaled by its maximum
value: RAND_MAX, so that the randomly
generated numbers are within [0,1).
*/
template <typename T>
int SkipList<T>::RandomLevel()
{
	int v = 1;

	while ((((double)rand() / RAND_MAX)) < probability &&
		abs(v) < maxLevel)
	{
		v += 1;
	}

	return abs(v);
}

/*
Function: nodeLevel()
Use: Implicitly in most of the member functions.

It returns the number of non-null pointers
corresponding to the level of the current node.
(the node that contains the checked vector of
forward pointers)

If list empty returns 1.
*/
template <typename T>
int SkipList<T>::NodeLevel(const Node<T>*& v)
{
	int currentLevel = 1;
	// last element's key is the largest
	int endNodeKey = numeric_limits<int>::max();

	if (v[0]->key == endNodeKey)
	{
		return currentLevel;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] != NULL && v[i]->key != endNodeKey)
		{
			++currentLevel;
		}
		else
		{
			break;
		}
	}

	return currentLevel;
}

// Non-modifying member functions
/*
Function: print()
Use: SkipList_obj.print();

It prints the key, value, level
of each node of the skip list.

Prints two nodes per line.
*/
template <typename T>
void SkipList<T>::Print() const
{
	Node<T>* list = startNode;
	int lineLenght = 1;

	cout << "{";

	while (list->forward[0] != NULL)
	{
		cout << "value: " << list->forward[0]->value
			<< ", key: " << list->forward[0]->key
			<< ", level: " << nodeLevel(list->forward);

		list = list->forward[0];

		if (list->forward[0] != NULL)
		{
			cout << " : ";
		}

		if (++lineLenght % 2 == 0)
		{
			cout << "\n";
		}
	}

	cout << "}\n";
}

/*
Function: find()
Use: Node* found = SkipList_obj.find(searchKey);

It searches the skip list and
returns the element corresponding
to the searchKey; otherwise it returns
failure, in the form of null pointer.
*/
template <typename T>
Node<T>* SkipList<T>::Find(int searchKey) const
{
	Node<T>* x = startNode;
	unsigned int currentMaximum = nodeLevel(startNode->forward);

	for (unsigned int i = currentMaximum; i-- > 0;)
	{
		while (x->forward[i] != NULL && x->forward[i]->key < searchKey)
		{
			x = x->forward[i];
		}
	}

	x = x->forward[0];

	if (x->key == searchKey)
	{
		return x;
	}
	else
	{
		return NULL;
	}
}

// Modifying member functions
/*
Function: makeNode ()
Use: Implicitly in member function insert().

It wraps the Node constructor which creates
a node on the heap and returns a pointer to it.
*/
template <typename T>
Node<T>* SkipList<T>::MakeNode(int key, T val, int level)
{
	return new Node<T>(key, val, level);
}

/*
Function: insert();
Use: void insert(searchKey, newValue);

It searches the skip list for elements
with seachKey, if there is an element
with that key its value is reassigned to the
newValue, otherwise it creates and splices
a new node, of random level.
*/
template <typename T>
void SkipList<T>::Insert(int searchKey, T newValue) {
	// reassign if node exists 
	Node<T>* x = NULL;
	x = find(searchKey);
	if (x)
	{
		x->value = newValue;
		return;
	}

	// vector of pointers that needs to be updated to account for the new node
	Node<T>* update(startNode->forward);
	unsigned int currentMaximum = nodeLevel(startNode->forward);
	x = startNode;

	// search the list 
	for (unsigned int i = currentMaximum; i-- > 0;)
	{
		while (x->forward[i] != NULL && x->forward[i]->key < searchKey)
		{
			x = x->forward[i];
		}

		update[i] = x;
	}

	x = x->forward[0];

	// create new node
	int newNodeLevel = 1;
	if (x->key != searchKey)
	{
		newNodeLevel = randomLevel();
		int currentLevel = nodeLevel(update);

		if (newNodeLevel > currentLevel)
		{
			for (int i = currentLevel + 1; i < newNodeLevel; ++i)
			{
				update[i] = startNode;
			}
		}

		x = makeNode(searchKey, newValue, newNodeLevel);
	}

	// connect pointers of predecessors and new node to successors
	for (int i = 0; i < newNodeLevel; ++i)
	{
		x->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = x;
	}
}

/*
Function: Delete()
Use: SkipList_obj.Delete(searchKey)

It deletes the element containing
searchKey, if it exists.
*/
template <typename T>
void SkipList<T>::Delete(int searchKey)
{
	// vector of pointers that needs to be updated to account for the deleted node
	Node<T>* update(startNode->forward);
	Node<T>* x = startNode;
	unsigned int currentMaximum = nodeLevel(startNode->forward);

	// search and update pointers
	for (unsigned int i = currentMaximum; i-- > 0;)
	{

		while (x->forward[i] != NULL && x->forward[i]->key < searchKey)
		{

			x = x->forward[i];
		}

		update[i] = x;
	}

	x = x->forward[0];

	// update pointers and delete node 
	if (x->key == searchKey)
	{
		for (size_t i = 0; i < update.size(); ++i)
		{
			if (update[i]->forward[i] != x)
			{
				break;
			}

			update[i]->forward[i] = x->forward[i];
		}

		delete x;
	}
}
