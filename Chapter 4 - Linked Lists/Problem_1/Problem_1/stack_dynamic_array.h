#ifndef _STACK_DYNAMIC_ARRAY_H_
#define _STACK_DYNAMIC_ARRAY_H_

#include <iostream>  // cout
#include <memory>    // smart pointer
#include <exception> // exceptions

template<typename T>
class stack_Dynamic_Array
{
	std::size_t count;         // Number of actually stored objects.
	std::size_t capacity;      // Allocated capacity.
	std::unique_ptr<T[]> data; // Data element.

public:
	stack_Dynamic_Array() : count(0), capacity(0), data(nullptr) { };
	
	void clear() { data.release(); };

	// Adds new value, and if needed allocates more space.
	void push(T const &d)
	{
		if (capacity == count)
			resize();
		data[count++] = d;
	};

	T pop()
	{
		if (empty())
			throw std::out_of_range("stack empty");
		return data[--count];
	};

	const T top()
	{
		if (empty())
			throw std::out_of_range("stack empty");
		return data[count - 1];
	};

	bool empty() const { return count == 0; };

	std::size_t size() const { return count; };

private:
	// Allocates double old space.
	void resize()
	{
		capacity = capacity ? capacity*2 : 1;

		std::unique_ptr<T[]> spTemp(static_cast<T*>(data.release()));
		data.reset(new T[capacity]);

		for (std::size_t i = 0; i < count; i++)
			data[i] = spTemp[i];
	};
};
#endif
