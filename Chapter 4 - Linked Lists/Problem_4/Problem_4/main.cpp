#include <iostream>

#include "myList.h"

using namespace std;

int main()
{
	myList<int> ml;

	// Fill list with data.
	for (int i=5; i>0; i--)
		ml.push_front(i);

	// Display list.
	cout << "list: " << ml;

	// Find elements by counting from end of list.
	for (int i=0, j=0; j<6; j++)
		if (ml.nthFromEnd(i, j)) cout << j << " from end: " << i << endl;
}
