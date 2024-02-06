#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList() : things(nullptr), size(0)
{
  //TODO
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  itemCount = x.itemCount;

}

//Member Function to overload = operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

//Member Function to swap idiom
template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(headPtr, x.headPtr);
  std::swap(itemCount, x.size);
}

//Member Function to see if list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (size == 0);
}

//Member Function to get size 
template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return size;
}

//Member Function to insert new item in list
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  bool ableToInsert = (position >= 0) && (position <= size);

  if (ableToInsert)
  {
    auto newNodePtr = std::make_shared< Node<T> >(item);

    if (position == 0)
    {
      newNodePtr->setNext(headPtr);
    }
    else
    {
      auto prevPtr = getNodeAt(position - 1);

      newNodePtr->setNext(prevPtr->getNext());
      prevPtr->steNext(newNodePtr);
    }
    size++;
  }
  return ableToInsert;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  bool ableToInsert = (position >= 0) && (position <= size);

  if (ableToInsert)
  {
    auto newNodePtr = std::make_shared< Node<T> >(item);

    if (position == 0)
    {
      newNodePtr->setNext(headPtr);
    }
    else
    {
      auto prevPtr = getNodeAt(position - 1);

      newNodePtr->setNext(prevPtr->getNext());
      prevPtr->steNext(newNodePtr);
    }
    size--;
  }
  return ableToInsert;
}

//Member Function to clear list
template <typename T>
void LinkedList<T>::clear()
{
  size = 0;
  headPtr = nullptr;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position < 0 || position >= size)
    return T();

  
  

}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
