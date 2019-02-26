/* Implement a stable version of the selection sort algorithm. */

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// Selection sort.
template<class FwdIt, class Compare = std::less<>>
void selectionSort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
	for (auto it = first; it != last; ++it) 
	{
		auto const selection = std::min_element(it, last, cmp);
		std::iter_swap(selection, it);
		//assert(std::is_sorted(first, std::next(it), cmp));
	}
}

// Stable version of selection sort.
void stableSelectionSort(int* a, int n)
{
	// Iterate through array elements.
	for (int i = 0; i < n - 1; i++)
	{
		// Loop invariant: Elements till a[i - 1] are already sorted. 
		// Find minimum element from a[i] to a[n - 1]. 
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;

		// Move minimum element at current i. 
		int key = a[min];
		while (min > i)
		{
			a[min] = a[min - 1];
			min--;
		}

		a[i] = key;
	}
}

int main()
{
	int a[] = { 4, 5, 3, 2, 4, 1 };
	int n = sizeof(a)/sizeof(a[0]);

	//selectionSort(a, a + n, std::less<int>());
	stableSelectionSort(a, n);

	assert(std::is_sorted(a, a + n, std::less<int>()));

	std::for_each(a, a + n, [](int i) { cout << i << " "; });
	cout << endl;
}
