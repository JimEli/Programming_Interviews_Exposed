/*
   Discuss the stack data structure. Implement a stack in C++
   using either a linked list or a dynamic array, and justify
   your decision. Design the interface to your stack to be
   complete, consistent and easy to use.
*/

#include <iostream>

// 2 versions of stack.
#include "stack_linked_list.h"
#include "stack_dynamic_array.h"

using namespace std;

int main()
{
	//
	// Stack based upon linked-list.
	//
	stack_Linked_List<int> s1;

	cout << "stack is " << (s1.empty() ? "empty\n" : "not empty\n");
	cout << "size: " << s1.size() << endl;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << "size: " << s1.size() << endl;
	cout << "stack: " << s1.pop() << endl;
	cout << "stack: " << s1.top() << endl;
	s1.pop();
	cout << "stack: " << s1.top() << endl;
	s1.pop();
	cout << "stack is " << (s1.empty() ? "empty\n" : "not empty\n");
	cout << "size: " << s1.size() << endl;

	//
	// Stack based upon dynamic array.
	//
	stack_Dynamic_Array<int> s2;

	cout << "stack is " << (s2.empty() ? "empty\n" : "not empty\n");
	cout << "size: " << s2.size() << endl;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	cout << "size: " << s2.size() << endl;
	cout << "stack: " << s2.pop() << endl;
	cout << "stack: " << s2.top() << endl;
	s2.pop();
	cout << "stack: " << s2.top() << endl;
	s2.pop();
	cout << "stack is " << (s2.empty() ? "empty\n" : "not empty\n");
	cout << "size: " << s2.size() << endl;

}
