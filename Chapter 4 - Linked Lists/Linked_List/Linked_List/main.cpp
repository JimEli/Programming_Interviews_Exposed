// Simple Singly-Linked List test.
#include <iostream>
#include <cassert>

#include "list.h"

#ifdef _DEBUG
// Visual Leak Detector.
#include "C:\Program Files (x86)\Visual Leak Detector\include\vld.h"
#endif

using namespace std;

int main()
{
	list<int> l;

	cout << "list is " << (l.empty() ? "empty\n" : "not empty\n");
	try
	{
		cout << "list front is " << l.front() << endl;
	}
	catch (...)
	{
		cout << "exception caught\n";
	}
	cout << "list size is " << l.size() << endl;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	cout << "list front is " << l.front() << endl;

	l.reverse();

	cout << "list front is " << l.front() << endl;
	cout << "list size is " << l.size() << endl;
	cout << "list is " << l;

	l.remove(2);
	l.pop_front();

	cout << "list is " << l;
	cout << "list is " << (l.empty() ? "empty\n" : "not empty\n");

	l.pop_front();
	l.remove(5);
	l.remove(0);
	l.pop_front();

	cout << "list is " << l;
	cout << "list is " << (l.empty() ? "empty\n" : "not empty\n");
}
