#include "linked_list.hpp"

// Default Constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  size = 0;
  headPtr = nullptr;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

// Copy Constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
 size = x.size;
 Node<T>* OldPtr = x.headPtr;
 
 // If x.headPtr is empty, then headPtr is empty too
 if(OldPtr == nullptr)
  {
    headPtr = nullptr;
  }

//If not, then copy constructor does its job
else
  {
    headPtr = new Node<T>();
    headPtr->setItem(OldPtr->getItem());
    Node<T>* NewPtr = headPtr;
    OldPtr = OldPtr->getNext();
    while(OldPtr != nullptr)
    {
      T next = OldPtr->getItem();
      Node<T>* NewChange = new Node<T>(next);
      NewPtr->setNext(NewChange);
      OldPtr = OldPtr->getNext();
      NewPtr = NewPtr->getNext();
    }
  }
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
  std::swap(size, x.size);
  std::swap(headPtr, x.headPtr);
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

//Member Function to insert a item in the linked list
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //Checking if position is valid
  if(position > size || position < 0)
  {
    return false;
  }


  Node<T> *PTR = new Node<T>(item);
  // Case 1: if position is the first node on the list
  if (position == 0)
  {
    PTR->setNext(headPtr);
    headPtr = PTR;
  }
  //Case 2: if position is the last node on the list
  else if(position == size - 1)
  {
    Node<T> *prev = headPtr;

    while(prev->getNext() != nullptr)
    {
      prev = prev->getNext();
    }
    PTR->setNext(nullptr);
    prev->setNext(PTR);
  }
  //Case 3: if the position is somewhere in the middle
  else
  {
    Node<T> *prev = headPtr;
    for (std::size_t i = 0; i < position - 1; ++i)
    {
      prev = prev->getNext();
    }
    PTR->setNext(prev->getNext());
    prev->setNext(PTR);
  }
  
  //Increment size and return true;
  size++;
  return true;
}


//Member Function to remove the position parameter
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //Checking if position is valid
  if(position >= size || position < 0)
  {
    return false;
  }

  Node<T>* PTR = headPtr;

  //For-Loop to get the node where the position is at
  for (int i = 0; i < position; i++)
  {
    PTR = PTR->getNext();
  }

  //Going throught steps to remove the given positoin node
  PTR->setItem(headPtr->getItem());
  Node<T>* gone = headPtr;
  headPtr = headPtr->getNext();
  gone->setNext(nullptr);
  delete gone;
  gone = nullptr;

  //Decrement size and return true;
  size--;
  return true;
}

//Member Function to clear list
template <typename T>
void LinkedList<T>::clear()
{
  Node<T>* clear = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      clear->setNext(nullptr);

      delete clear;
      clear = headPtr;
   }
   size = 0;
}

//Member Function to get an item in the list
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //Checking validity of position
  if(position < 0 || position >= size)
  {
    return T();
  }
  else
  {
    Node<T>* set = headPtr;
    //For-Loop to get the node where the position is at
    for (int i = 0; i < position; i++)
    {
      set = set->getNext();
    }
    return set->getItem();
  }
}

//Member Function to replace an item in the list
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //Checking validity of position
  if(position < 0 || position >= size)
  {
    return;
  }
  else
  {
    Node<T>* set = headPtr;
    //For-Loop to get the node where the position is at
    for (int i = 0; i < position; i++)
    {
      set = set->getNext();
    }
    set->setItem(newValue);
  }
}