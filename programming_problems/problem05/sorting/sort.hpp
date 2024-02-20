#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"
#include <algorithm>

// I HAVE DECIDED TO IMPLEMENT THE BUBBLE SORT ALGORITHM TO SORT THE LINKED LIST VALUES
// THERE ARE 3 IMPORTANT STEPS TO THIS ALGORITHM:

// 1. WE HAVE TO ITERATE THOUGH EVERY ITEM IN THE LIST
// 2. IF THE NEXT NUMBER IS SMALLER THAN THE PREVIOUS NUMBER, THEN WE SWAP THERE PLACES TO MAKE IT ASCENDING ORDER
// 3. WE DO THIS UNTIL THERE ARE NO MORE ELEMENTS TO COMPARE

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	// Nest For-Loops to iterate thourgh all elements and swap if necessary 
	for (int i = 0; i < list.getLength(); i++)
	{
		for (int j = 0; j < list.getLength() - i - 1; j++)
		{
			// If-Statement to compare the two elements in the conditions and swapping them if necessary
			if (list.getEntry(j) > list.getEntry(j+1))
			{
				//std::swap(list.getEntry(j), list.getEntry(j+1));
				// Swapping manually, since the std::swap function did not work here
				T temp = list.getEntry(j);
				list.setEntry(j, list.getEntry(j+1));
				list.setEntry(j+1, temp);
			}
		}
	}

	//Returning the sorted list
	return list;
}

#endif
