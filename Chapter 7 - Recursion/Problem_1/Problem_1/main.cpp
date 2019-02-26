/*
   Implement a function to perform a binary search on a sorted array
   of integers to find the index of a given integer. Comment on the 
   efficiency of this search, and compare it with other search methods.
*/
#include <iostream>
#include <algorithm>
#include <cassert>

constexpr unsigned ARRAY_SIZE{ 10000 };

int binarySearch(int sortedArray[], int first, int last, int key)
{
	if (first <= last)
	{
		// Compute mid point.
		int mid = (first + last) / 2;

		if (key == sortedArray[mid])
			return mid;
		else if (key < sortedArray[mid])
			// Recurse lower part of the array.
			return binarySearch(sortedArray, first, mid - 1, key);
		else
			// Recurse upper part of the array.
			return binarySearch(sortedArray, mid + 1, last, key);
	}

	return -1;
}

bool bBinarySearch(int sortedArray[], int first, int last, int key)
{
	if (first <= last)
	{
		// Compute mid point.
		int mid = (first + last) / 2;

		if (key == sortedArray[mid])
			return true;
		else if (key < sortedArray[mid])
			// Recurse lower part of the array.
			return bBinarySearch(sortedArray, first, mid - 1, key);
		else
			// Recurse upper part of the array.
			return bBinarySearch(sortedArray, mid + 1, last, key);
	}

	return false;
}

int main()
{
	int arr[ARRAY_SIZE], target=0;

	for (unsigned i = 1; i < ARRAY_SIZE; i++)
		arr[i] = i;

	std::cout << "Enter number (0 - " << ARRAY_SIZE << ") to search for: ";
	std::cin >> target;

	assert(std::binary_search(arr, arr + ARRAY_SIZE, target) == bBinarySearch(arr, 0, ARRAY_SIZE, target));

	std::cout << "key: " << binarySearch(arr, 0, ARRAY_SIZE, target) << std::endl;
}