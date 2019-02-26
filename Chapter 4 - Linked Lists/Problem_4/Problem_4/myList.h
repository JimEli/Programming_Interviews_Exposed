#include "list.h"

template <typename T>
class myList : public list<T>
{
	// Return nth node from end (end == 0).
	list<T>::node* nth(int n)
	{
		auto current{ list<T>::head }, nBehind{ list<T>::head };

		for (int i = 0; i < n; i++)
		{	// Locate n elements behind current node.
			if (!current->next)
				return nullptr;
			current = current->next;
		}

		while (current->next)
		{	// Continue walking list to end.
			nBehind = nBehind->next;
			current = current->next;
		}

		return nBehind;
	}

public:
	// Return n-th from end element.
	bool nthFromEnd(T& e, int n)
	{	
		auto x = nth(n);
		
		if (x)
		{
			e = x->element;
			return true;
		}
		else
			return false;
	}

};