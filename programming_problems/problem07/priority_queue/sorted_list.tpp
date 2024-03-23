#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // If-Statement to insert the item to the beginning of the list if the list is empty
  if (isEmpty())
  {
    plist.insert(0, item);
    return;
  }
  // Else, find the position where the item is at
  int position = 0;
  while (position < getLength() && item > plist.getEntry(position))
  {
    position++;
  }
  
  // Then, insert the item in the position found above using the List insert function
  plist.insert(position, item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  // If-Statement to throw an exception if the list is empty
  if (isEmpty())
  {
    throw std::range_error("Nothing to remove");
  }
  // Else, find the position where the item is at
  int position = 0;
  while (item > plist.getEntry(position))
  {
      position++;
  }
  // Removing the item in the position found above using the List remove function
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // For-Loop that goes through the items in the list
  for (int i = 0; i < plist.getLength(); i++)
  {
    // If-Statement that check if the item in the parameter is equal to the list item being compared
    if (newValue == plist.getEntry(i))
    {
      // If so, then return the position, which is i in this case
      return i;
    }
  }
  // If the item is not found, then return -1
  return -1;
}
