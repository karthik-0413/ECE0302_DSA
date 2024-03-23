#include "list.hpp"

template <typename T>
List<T>::List()
{
  // Default Constructor
  size = 0;
  capacity = 100;
  things = new T[capacity];
  for (int i = 0; i < size; i++)
  {
    *(things + i) = 0;
  }
}

// destructor
template <typename T>
List<T>::~List()
{
  // Deallocate pointer 
  delete[] things;
}

template <typename T>
List<T>::List(const List<T>& x)
{
  // Copy Constructor
  size = x.size;
  capacity = x.capacity;
  things = new T[capacity];

  //For-Loop to copy all of contents in things to rhs.things
  for(int i = 0; i < size; i++)
  {
    things[i] = x.things[i];
  }
}

// copy assignment
template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

// swap function to help with copy assignment
template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(size, x.size);
  std::swap(capacity, x.capacity);
  std::swap(things, x.things);
}

// determine if a list is empty
template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return size == 0;
}

// return current length of the list
template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return size;
}

// insert item at position in the list
template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{

  //Checking if position is valid
  if (position > size || position < 0)
  {
    return;
  }

  // FOLLOWING OUTLINE THAT WAS GIVEN TO US IN CLASS
  else if (size == capacity)
  {
    // need to reallocate
    capacity += 100;
    T* newPtr = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
      *(newPtr + i) = *(things + i);
    }
    delete[] things;
    things = newPtr;
  }

  //For-Loop to get the items other than the position index to be the same
  for (std::size_t i = size; i > position; --i)
  {
    *(things + i) = *(things + (i-1));
  }

  //Assigning the position in the parameter to the item in the parameter
  things[position] = item;
  size++;
}

// remove item at position in the list
template <typename T>
void List<T>::remove(std::size_t position)
{
  //Checking if position is valid
  if (position > size || position < 0)
  {
    return;
  }

  size--;

  //For-Loop to shift all of the items in the list left to remove the position item
  for(int i = position; i < size; i++)
  {
    *(things + i) = *(things + (i+1));
  }
}

// remove all items from the list
template <typename T>
void List<T>::clear()
{
  size = 0;
}

// get a copy of the item at position
template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  //Checking if position is valid
  if(position < 0 || position >= size)
    return T();

  return *(things + position);
}

// set the value of the item at position 
template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //Checking if position is valid
  if (position < size && position >= 0)
  {
    *(things + position) = newValue;
  }
}
