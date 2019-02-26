#ifndef _STACK_LINKED_LIST_H_
#define _STACK_LINKED_LIST_H_

#include <iostream>  // cout
#include <memory>    // smart pointer
#include <exception> // exceptions

template <typename T>
class stack_Linked_List
{
protected:
	template <typename T>
	struct node
	{
		explicit node(T e) { element = e; }
		T element;
		std::shared_ptr<node<T>> next = nullptr;
	};

public:
	void push(const T& e)
	{
		auto newNode{ std::make_shared<node<T>>(e) };
		newNode->element = e;
		newNode->next = head;
		head = newNode;
	}

	T pop()
	{
		if (empty())
			throw std::out_of_range("stack empty");
		T e = top();
		auto temp{ head };
		head = head->next;
		return e;
	}

	const T top() const
	{
		if (empty())
			throw std::out_of_range("stack empty");
		return head->element;
	}

	bool empty() const { return head == nullptr; }
	
	std::size_t size() const
	{
		std::size_t size = 0;
		for (auto node = head; node; node = node->next, size++);
		return size;
	}

private:
	std::shared_ptr<node<T>> head = nullptr;
};

#endif
