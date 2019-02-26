#include <iostream>
#include <algorithm>

#include "xList.h"

int main()
{
	xList<int> xl;

	// Fill list.
	for (int i = 1; i < 6; i++)
		xl.push_back(i);

	// Remove and insert after.
	xl.remove(3);
	xl.insertAfter(2, 3);

	// Display list.
	std::cout << "list: ";
	std::for_each(xl.begin(), xl.end(), [](int i){ std::cout << i; });
	std::cout << std::endl;
	
	return 0;
}
