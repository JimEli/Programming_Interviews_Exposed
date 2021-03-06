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
protected:
	node<T>* head = nullptr, *tail = nullptr;

public:
	~list() { clear(); }

	friend std::ostream& operator<< (std::ostream& os, const list<T>& list)
	{
		for (const node<T> *node = list.head; node; node = node->next)
			os << node->element;
		return os << std::endl;
	}

	void clear()
	{
		while (!empty())
			pop_front();
		head = tail = nullptr;
	}

	std::size_t size() const
	{
		std::size_t size = 0;
		for (const node<T>* node = head; node; node = node->next, size++);
		return size;
	}

	bool empty() const { return head == nullptr; }

	T& front() const { return head->element; }
	T& back() const { return tail->element; }

	void push_back(const T& e)
	{
		node<T>* newNode = new node<T>(e);
		if (!head)
			head = newNode;
		if (tail)
			tail->next = newNode;
		tail = newNode;
	}

	void push_front(const T& e)
	{
		node<T>* newNode = new node<T>(e);
		if (!tail)
			tail = newNode;
		newNode->next = head;
		head = newNode;
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
};

#endif
