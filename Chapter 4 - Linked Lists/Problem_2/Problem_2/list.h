#ifndef _BASIC_LIST_H_
#define _BASIC_LIST_H_

#include <iostream>  // cout

template <typename T>
struct node
{
	node(T e) : element(e) { }

	T element;
	node<T>* next = nullptr;
};

template <typename T>
class list 
{
public:
	~list() { clear(); }

	bool empty() const { return head == nullptr; }

	void push_back(const T& e)
	{
		node<T>* newNode = new node<T>(e);
		if (!head)
			head = newNode;
		if (tail)
			tail->next = newNode;
		tail = newNode;
	}

	void pop_front()
	{
		if (empty())
			return;
		node<T>* temp = head;
		head = head->next;
		if (tail == temp)
			tail = nullptr;
		delete temp;
	}

	void clear()
	{
		while (!empty())
			pop_front();
		head = tail = nullptr;
	}

	// Inner iterator class. Member typedefs provided through inheritance from std::iterator.
	class iterator : public std::iterator<std::forward_iterator_tag, T>
	{
	private:
		node<T> *pnode = nullptr;
		// Ctor is private, so only friends can create instances.
		iterator(node<T> *n) : pnode(n) { }
		friend class list;

	public:
		// Overload comparison operators.
		bool operator== (const iterator& it) const { return pnode == it.pnode; }
		bool operator!= (const iterator& it) const { return pnode != it.pnode; }
		// Overload dereference and pointer operators.
		T& operator* () { return pnode->element; }
		T* operator-> () { return &pnode->element; }
		// Overload prefix increment operator.
		iterator& operator++ ()
		{
			pnode = pnode->next;
			return *this;
		}
	}; // End iterator inner class.

	// Begin and end iterators.
	iterator begin() const { return iterator(head); }
	iterator end() const { return iterator(tail->next); } // { return iterator(tail); }

protected:
	node<T>* head = nullptr, *tail = nullptr;
};

#endif
