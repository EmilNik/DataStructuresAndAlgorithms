#include <iostream>
#include <string>

using namespace std;

#include "SkipList.h"

//==================================================
int main() {

	// 1.Initialize an empty Skip_list object
	SkipList<int> s;

	// 2. insert()
	for (int i = 0; i < 50; ++i) {

		s.Insert(i, i);
	}

	// 2a. print()
	s.Print();

	// 3. find()
	Node<int>* f = NULL;
	f = s.Find(10);
	if (f)
	{
		cout << "Node found!\nvalue: " << f->value << '\n';
	}
	else
	{
		cout << "Node NOT found!\n";
	}

	// 4. insert() - reassign
	s.Insert(40, 9999);

	// 4a. print()
	s.Print();

	// 5. erase()
	s.Delete(40);

	// 5a. print();
	s.Print();

	cout << "\nDone!\n";
	getchar();
}
