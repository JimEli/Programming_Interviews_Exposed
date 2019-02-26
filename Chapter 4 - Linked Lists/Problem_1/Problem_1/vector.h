#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <memory> // unique pointer

template<typename T>
class vector
{
	std::size_t count;         // Number of actually stored objects.
	std::size_t capacity;      // Allocated capacity.
	std::unique_ptr<T[]> data; // Data element.

public:
	vector() : count(0), capacity(0), data(nullptr) { };
	
	void clear() { data.release(); };

	// Provides memory management.
	vector &operator= (vector const &rhs)
	{
		std::unique_ptr<T[]> temp(static_cast<T*>(data.release()));

		count = rhs.count;
		capacity = rhs.capacity;
		data.reset(new T[capacity]);
		
		for (std::size_t i = 0; i < count; i++)
			data[i] = temp[i];

		return *this;
	};

	// Adds new value, and if needed allocates more space.
	void push_back(T const &d)
	{
		if (capacity == count)
			resize();
		data[count++] = d;
	};

	void pop_back()
	{
		if (count == 0)
			return;
		count--;
	};

	size_t size() const { return count; };

	// Bracketed set/get.
	T const &operator[] (size_t i) const { return data[i]; };
	T &operator[] (size_t i) { return data[i]; };

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
