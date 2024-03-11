#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  // Declaring a temp list to sort at the end of the BUBBLE SORT
  LinkedList<T> temp = unsorted_list;

  // Nest For-Loops to iterate thourgh all elements and swap if necessary 
	for (int i = 0; i < temp.getLength(); i++)
	{
		for (int j = 0; j < temp.getLength() - i - 1; j++)
		{
			// If-Statement to compare the two elements in the conditions and swapping them if necessary
			if (temp.getEntry(j) > temp.getEntry(j+1))
			{
				//std::swap(unsorted_list.getEntry(j), unsorted_list.getEntry(j+1));
				// Swapping manually, since the std::swap function did not work here
				T temp2 = temp.getEntry(j);
				temp.setEntry(j, temp.getEntry(j+1));
				temp.setEntry(j+1, temp2);
			}
		}
	}

  // Trasnferring the new sorted list into the new made list
  for (int i = 0; i < temp.getLength(); ++i)
  {
    LinkedList<T>::insert(i, temp.getEntry(i));
  }
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  // If-Statement to insert the item to the beginning of the list if the list is empty
  if (isEmpty())
  {
    LinkedList<T>::insert(0, item);
    return;
  }
  // Else, find the position where the item is at
  int position = 0;
  while (position < getLength() && item > LinkedList<T>::getEntry(position))
  {
    position++;
  }
  
  // Then, insert the item in the position found above using the Linked List insert function
  LinkedList<T>::insert(position, item);
}


template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  // If-Statement to throw an exception if the list is empty
  if (isEmpty())
  {
    throw std::range_error("Nothing to remove");
  }
  // Else, find the position where the item is at
  int position = 0;
  while (item > LinkedList<T>::getEntry(position))
  {
      position++;
  }
  // Removing the item in the position found above using the Linked List remove function
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  // If-Statement to throw an exception if the list is empty
  if(isEmpty())
  {
    throw std::range_error("empty list in remove");
  }
  // Else, removing the position in the parameter using the Linked List remove function
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  // For-Loop that goes through the items in the list
  for (int i = 0; i < LinkedList<T>::getLength(); i++)
  {
    // If-Statement that check if the item in the parameter is equal to the list item being compared
    if (item == LinkedList<T>::getEntry(i))
    {
      // If so, then return the position, which is i in this case
      return i;
    }
  }
  // If the item is not found, then return -1
  return -1;
}

