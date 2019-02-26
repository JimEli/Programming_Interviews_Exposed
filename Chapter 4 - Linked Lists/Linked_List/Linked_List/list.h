#ifndef _LIST_H
#define _LIST_H

template <typename T>
class list
{
	struct node
	{
		explicit node(T e) : element(e) { }
		T element;
		node* next = nullptr;
	};

	node* head = nullptr;

public:
	~list() { clear(); }

	bool empty() { return head == nullptr; }

	std::size_t size()
	{
		std::size_t sz = 0;
		for (const node* n = head; n; n = n->next, sz++);
		return sz;
	}

	void clear()
	{
		while (!empty())
			pop_front();
	}

	void push_front(T e)
	{
		auto newNode = new node(e);
		newNode->next = head;
		head = newNode;
	}

	T pop_front()
	{
		if (empty())
			throw std::out_of_range("list empty");
		T e = head->element;
		auto temp = head;
		head = head->next;
		delete temp;
		return e;
	}

	T front()
	{
		if (empty())
			throw std::out_of_range("list empty");
		return head->element;
	}

	friend std::ostream& operator<< (std::ostream& os, list<T>& l)
	{
		for (node* n = l.head; n; n=n->next)
			os << n->element << " ";
		return os << "\n";
	}

	//
	// Beyond basics.
	//

	void remove(T e)
	{
		if (empty())
			return;
		auto node = head, prev = node;
		do
		{
			if (node->element == e)
			{
				if (node == head)
					head = node->next;
				prev->next = node->next;
				delete node;
				return;
			}
			prev = node;
			node = node->next;
		} while (node);
	}

	node* reverse(node* curr, node* prev = nullptr)
	{
		if (!curr)
			return prev;
		node* next = curr->next;
		curr->next = prev;
		return reverse(next, curr);
	}
	void reverse() { head = reverse(head); }

};

#endif