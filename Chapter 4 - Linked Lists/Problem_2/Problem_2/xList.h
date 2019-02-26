#include "list.h"

template <typename T>
class xList : public list<T>
{
	// Remove first occurrance of e. 
	bool removeNode(T e)
	{
		if (list<T>::empty())
			return false;

		auto n{ list<T>::head }, prev{ n };
		
		do {
			if (n->element == e)
			{
				if (n == list<T>::head)        // 1st node.
				{
					list<T>::head = n->next;
					if (list<T>::tail == n)    // Only 1 node.
						list<T>::tail = nullptr;
					delete n;
					return true;
				}

				prev->next = n->next; // Interior node.

				if (n == list<T>::tail)        // Tail node.
					list<T>::tail = prev;

				delete n;
				return true;
			}
			prev = n;
			n = n->next;
		} while (n);

		return false;
	}

	// Insert element after node.
	bool insertAfter(node<T>* n, T e)
	{
		auto newNode = new node<T>(e);

		newNode->next = n->next;

		if (n == list<T>::tail || n->next == list<T>::tail)
			list<T>::tail = newNode;
		
		n->next = newNode;
		return true;
	}

	// Find and return node.
	node<T>* find(const T& e)
	{
		if (list<T>::empty())
			return nullptr;

		auto node = list<T>::head;

		// Walk list looking for node match.
		do {
			if (node->element == e)
				return node;
			node = node->next;
		} while (node);

		return nullptr;
	}

public:
	// Remove all elements "e" from list.
	void remove(T e) { while (removeNode(e)); }

	// Insert the element "eInsert" after element "eAfter".
	// If no element "eAfter" exists, return false.
	bool insertAfter(T eAfter, T eInsert)
	{
		auto n = find(eAfter);

		if (n)
			return insertAfter(n, eInsert);
		
		return false;
	}

	// Note above insertAfter implementation doesn't support insert at head.
	// Use following push_front to accomplish this functionality.
	void push_front(const T& e)
	{
		auto newNode = new node<T>(e);

		if (!list<T>::tail)
			list<T>::tail = newNode;
		
		newNode->next = list<T>::head;
		list<T>::head = newNode;
	}
};